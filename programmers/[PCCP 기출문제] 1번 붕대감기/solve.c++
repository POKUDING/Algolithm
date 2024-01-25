function solution(bandage, health, attacks) {
    //최초 공격받은 데미지 적용
    let leftH = health - attacks[0][1];
    if(leftH <= 0)
        return -1;
    for (let i = 1; i < attacks.length; ++i) {
        //i번째 공격과 이전 공격간의 시간 차
        const time = attacks[i][0] - attacks[i - 1][0] - 1;
        //시간차이만큼 체력회복
        leftH += (bandage[1] * time) + (Math.floor(time / bandage[0]) * bandage[2]);
        //오버힐 방지
        if (leftH > health)
            leftH = health;
        //i번째 공격 데미지 적용
        leftH -= attacks[i][1];
        //공격받은 이후 죽었는지 확인
        if(leftH <= 0)
            return -1;   
    }
    return leftH;
}