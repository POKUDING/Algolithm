function solution(n, stations, w) {
    var answer = 0;
    
    for(let i = n; i > 0; --i) {
        if(i <= stations[stations.length - 1] + w && i >= stations[stations.length - 1] - w) {
            i = stations[stations.length - 1] - w;       
            stations.pop();
        }
        else {
            ++answer;
            i -= 2 * w;
        }
    }
    return answer;
}