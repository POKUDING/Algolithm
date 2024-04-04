import java.util.*;

class Solution {
    public int[] solution(int n) {
        int[][] arr = new int[n][n];
        int[][] dir = new int[][]{{1,0},{0,1},{-1,-1}};
        int[]   pos = new int[]{-1,0};
        int curr_step = 1, curr_dir = 0;
        for(int i = n; i > 0; --i) {
            for(int j = i; j > 0; --j) {
                pos[0] += dir[curr_dir][0];
                pos[1] += dir[curr_dir][1];
                arr[pos[0]][pos[1]] = curr_step++;
            }
            curr_dir = (curr_dir + 1) % 3;
        }
        ArrayList<Integer> answer = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i + 1; ++j)
                answer.add(arr[i][j]);
        }
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}