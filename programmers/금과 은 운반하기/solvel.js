function isPossible(a, b, g, s, w, t, time) {
    const len = g.length;
    let total = 0;
    let totalG = 0;
    let totalS = 0;
    
    for(let i = 0; i < len; ++i) {
        let cnt = Math.floor(time / (2 * t[i]));
        if (time % (2 * t[i]) >= t[i]) ++cnt;
        
        const tmp = Math.min(w[i] * cnt, g[i] + s[i]);
        total += tmp;
        totalG += Math.min(tmp, g[i]);
        totalS += Math.min(tmp, s[i]);
    }
    return (total >= a + b && totalG >= a && totalS >= b)
}

function solution(a, b, g, s, w, t) {
    let low = 0;
    let high = 400000000000000;
    
    while(low + 1< high) {
        const mid = Math.floor((low + high) / 2);
        if(isPossible(a,b,g,s,w,t,mid))
            high = mid;
        else
            low = mid;
    }
    return high;
}