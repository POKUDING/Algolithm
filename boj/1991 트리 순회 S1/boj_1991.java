import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static Map<Character,char[]> map = new HashMap<>();
    static StringBuilder sb = new StringBuilder();

    public static void init() throws Exception {
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; ++i){
            String read = br.readLine();
            map.put(read.charAt(0),new char[] {read.charAt(2), read.charAt(4)});
        }
    }

    public static void solveFront(Character node) {
        sb.append(node);
        if(map.get(node)[0] != '.')
            solveFront(map.get(node)[0]);
        if(map.get(node)[1] != '.')
            solveFront(map.get(node)[1]);
    }

    public static void solveMid(Character node) {
        if(map.get(node)[0] != '.')
            solveMid(map.get(node)[0]);
        sb.append(node);
        if(map.get(node)[1] != '.')
            solveMid(map.get(node)[1]);
    }
    public static void solveBack(Character node) {
        if(map.get(node)[0] != '.')
            solveBack(map.get(node)[0]);
        if(map.get(node)[1] != '.')
            solveBack(map.get(node)[1]);
        sb.append(node);
    }
    public static void main(String[] args) throws Exception{
        init();
        solveFront('A');
        System.out.println(sb.toString());
        sb.setLength(0);
        solveMid('A');
        System.out.println(sb.toString());
        sb.setLength(0);
        solveBack('A');
        System.out.println(sb.toString());        
    }
}