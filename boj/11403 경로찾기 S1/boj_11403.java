import java.util.*;
import java.lang.*;
import java.io.*;

import java.util.stream.Collectors;

// The main method must be in a class named "Main".
class Main {
    static int[][] result;
    static int n;

    public static void floydWarshall() {
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n ; ++i)
                for(int j = 0; j < n; ++j)
                    if(result[i][k] == 1 && result[k][j] == 1)
                        result[i][j] = 1;
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        result = new int[n][n];
        for(int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; ++j)
                if(Integer.parseInt(st.nextToken()) == 1)
                    result[i][j] = 1;
        }
    }

    public static void print() {
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                sb.append(result[i][j]).append(" ");
            sb.append("\n");
        }
        System.out.println(sb);
    }
    
    public static void main(String[] args) throws Exception {
        init();
        floydWarshall();
        print();
    }
}