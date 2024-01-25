function solution(cookie) {
    let son1 = son2 = 0;
    let m = 0;
    let ans = 0;

    if (cookie.length === 1)
        return 0;
    son1 = cookie[0];
    for(let i = m + 1; i< cookie.length; ++i){
        son2 += cookie[i];
    }
    while(m < cookie.length - 1) {
        let left_idx = 0;
        let rigth_idx = cookie.length - 1;
        let son1_tmp = son1;
        let son2_tmp = son2;
        while(left_idx <= m && rigth_idx > m) {
            if (son1_tmp === son2_tmp) {
                ans = Math.max(son1_tmp, ans);
                break;   
            }
            if (son1_tmp < son2_tmp)
                son2_tmp -= cookie[rigth_idx--];
            if (son1_tmp > son2_tmp)
                son1_tmp -= cookie[left_idx++];
        }
        son1 += cookie[++m];
        son2 -= cookie[m];
    }
    return ans;
}