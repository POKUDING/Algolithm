import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int res = 0;
    static int removeNum;
    static Map<Integer,ArrayList<Integer>> map = new HashMap<>();
    public static void init() throws Exception {
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = -1; i < N; ++i)
            map.put(i, new ArrayList<Integer>());
        for(int i = 0; i < N; ++i) {
            Integer root = Integer.parseInt(st.nextToken());
            map.get(root).add(i);
        }
        removeNum = Integer.parseInt(br.readLine());
    }

    public static void solve(int node) {
        if(node == removeNum)
            return ;
        int size = 0;
        for(int i = 0; i < map.get(node).size(); ++i) {
            if(map.get(node).get(i).equals(removeNum))
                continue;
            solve(map.get(node).get(i));
            ++size;
        }
        if(node != -1 && size == 0) {
            ++res;
        }
    }
    public static void main(String[] args) throws Exception {
        init();
        solve(-1);
        System.out.println(res);
    }
}