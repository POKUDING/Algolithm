import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    static int N;
    static Map<Integer,int[]> map = new HashMap<>();
    static Map<Integer,int[]> lens = new HashMap<>();
    // static boolean isNotRoot[];
    static int root;
    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        // isNotRoot = new boolean[N + 1];
        root = N * (N + 1)/2;
        for(int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int pNode = Integer.parseInt(st.nextToken());
            int lNode = Integer.parseInt(st.nextToken());
            int rNode = Integer.parseInt(st.nextToken());
            map.put(pNode,new int[]{ lNode, rNode});
            if(lNode != -1)
                root -= lNode;
            if(rNode != -1)
                root -= rNode;

            // if(lNode != -1)
            //     isNotRoot[lNode] = true;
            // if(rNode != -1)
            //     isNotRoot[rNode] = true;
        }
    }

    public static int dfs(int curr, int level, int head) {
        int left = 0;
        int right = 0;
        if(map.get(curr)[0] != -1)
            left = dfs(map.get(curr)[0], level + 1, head);
        if(lens.get(level) == null)
            lens.put(level,new int[] {left + head + 1, left + head + 1});
        else {
            lens.get(level)[0] = Math.min(lens.get(level)[0], left + head + 1);
            lens.get(level)[1] = Math.max(lens.get(level)[1], left + head + 1);
        }
        if(map.get(curr)[1] != -1)
            right = dfs(map.get(curr)[1], level + 1, head + left + 1);
        return left + right + 1;
    }

    // public static int findRoot() {
    //     for(int i = 1; i <= N; ++i)
    //         if(isNotRoot[i] == false)
    //             return i;
    //     return 0;
    // }

    public static void solve() {
        // int root = findRoot();
        dfs(root, 1, 0);
        int ansLevel = 0;
        int maxLen = -1;
        for(Map.Entry<Integer,int[]> len : lens.entrySet()) {
            // System.out.println(len.getKey() + " " + len.getValue()[0] + " "+ len.getValue()[1]);
            if(len.getValue()[1] - len.getValue()[0] > maxLen) {
                maxLen = len.getValue()[1] - len.getValue()[0];
                ansLevel = len.getKey();
            }
        }
        System.out.println(ansLevel + " " + (maxLen + 1));
    }
    
    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}