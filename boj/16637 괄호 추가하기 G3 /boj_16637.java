import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int N, max = Integer.MIN_VALUE;
    static char[] input;

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        input = br.readLine().toCharArray();
    }

    public static void dfs(int idx, int sum) {
        if(idx == N - 1) {
            max = Math.max(max, sum);
            return ;
        }
        dfs(idx + 2, calc(sum, input[idx + 1], input[idx + 2] - '0'));
        if(idx + 4 < N)
            dfs(idx + 4, calc(sum, input[idx + 1], calc(input[idx + 2] -'0', input[idx + 3], input[idx + 4] - '0')));
    } 

    public static int calc(int num1, char oper,int num2) {
        switch(oper) {
            case '+':
                return num1 + num2;
            case '*':
                return num1 * num2;
            case '-':
                return num1 - num2;
        }
        return 0;
    }

    public static void main(String[] args) throws Exception {
        init();
        dfs(0, input[0] - '0');
        System.out.println(max);
    }
}