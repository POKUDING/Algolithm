function solution(nodeinfo) {
    const answer = [[],[]];
    const inodeinfo = [];
    for(const key in nodeinfo)
        inodeinfo.push([...nodeinfo[key],Number(key) + 1])
    inodeinfo.sort((a,b)=> a[0] - b[0]);
    const finder = (info) => {
        if (info.length) {
        let high = [0,-1,0];
        let highIdx = 0;
        for(let i =0; i < info.length; ++i){
            if(info[i][1] > high[1]) { 
                high = info[i];
                highIdx = i;
            }
        }
        console.log(high);
        answer[0].push(high[2]);
        finder(info.slice(0,highIdx));
        finder(info.slice(highIdx + 1));
        answer[1].push(high[2]);
    }}
    finder(inodeinfo);
    console.log(answer);
    return answer;
}