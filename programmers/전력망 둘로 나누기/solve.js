function countNode(tree, n, start, except) {
    const visit = Array(n + 1).fill(false);
    let   count = 0;
    
    visit[start] = true;
    function dfs(tree, node, visit, n) {
        for(let i = 1; i <= n; ++i) {
            const nodes = tree[node][i];
            if (visit[i]|| !nodes || (node === start && i === except))
                continue;
            visit[i] = true;
            dfs(tree, i, visit, n);
        }
    }
    dfs(tree, start, visit, n);
    for(const node of visit) {
        if(node)
            ++count;
    }
    // console.log(start, except, "Visit= ", visit, count);
    return count;
}

function solution(n, wires) {
    const tree = Array.from(Array(n + 1), () => Array(n + 1).fill(false) );
    for(const wire of wires) {
        tree[wire[0]][wire[1]] = true;
        tree[wire[1]][wire[0]] = true;
    }
    let answer = n;
    for(const wire of wires) {
        answer = Math.min(Math.abs(n - 2 * countNode(tree, n, wire[0],wire[1])), answer);
    }
    return answer;
}