class Solution {
    public int solution(int[][] triangle) {
        int curr_y = triangle.length - 1;
        while(--curr_y >= 0) {
            for(int i = 0; i < triangle[curr_y].length; ++i) {
                triangle[curr_y][i] += Math.max(triangle[curr_y + 1][i],
                                             triangle[curr_y + 1][i + 1]);
            }
        }
        return triangle[0][0];
    }
}