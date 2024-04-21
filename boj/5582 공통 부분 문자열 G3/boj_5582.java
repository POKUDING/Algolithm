import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static char[] str1;
    static char[] str2;
    static int[][] dp;
    static int max;

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str1 = br.readLine().toCharArray();
        str2 = br.readLine().toCharArray();
        dp = new int[str1.length + 1][str2.length + 1];
    }

    public static void solve() {
        for(int i = 0; i < str1.length; ++i) {
            for(int j = 0; j < str2.length; ++j){
                if(str1[i] == str2[j]) {
                        dp[i + 1][j + 1] = dp[i][j] + 1;
                    max = Math.max(max, dp[i + 1][j + 1]);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        init();
        solve();
        System.out.println(max);
    }
}