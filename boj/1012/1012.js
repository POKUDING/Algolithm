const fs = require("fs");
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const T = Number(input.shift());

const inputArr = input.map((val) => val.split(" ").map(Number));

for (let i = 0; i < T; ++i) {
    let ans = 0;
    const que = [];
    const [M, N, K] = inputArr.shift();

    farm = Array.from(Array(N), () => new Array(M).fill(0));
    for (let j = 0; j < K; ++j) {
        const [x, y] = inputArr.shift();
        farm[y][x] = 1;
    }
    for (let y = 0; y < N; ++y) {
        for (let x = 0; x < M; ++x) {
            if (farm[y][x] === 1) {
                ++ans;
                que.push([x, y]);
                while (que.length > 0) {
                    const [curr_x, curr_y] = que.shift();
                    if (farm[curr_y][curr_x] === 0)
                        continue ;
                    farm[curr_y][curr_x] = 0;
                    if (curr_y - 1 >= 0 && farm[curr_y - 1][curr_x] === 1)
                        que.push([curr_x, curr_y - 1]);
                    if (curr_y + 1 < N && farm[curr_y + 1][curr_x] === 1)
                        que.push([curr_x, curr_y + 1]);
                    if (curr_x - 1 >= 0 && farm[curr_y][curr_x - 1] === 1)
                        que.push([curr_x - 1, curr_y]);
                    if (curr_x + 1 < M && farm[curr_y][curr_x + 1] === 1)
                        que.push([curr_x + 1, curr_y]);
                }
            }
        }
    }
    console.log(ans);
}
