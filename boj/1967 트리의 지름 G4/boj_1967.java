import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static Map<Integer,ArrayList<Integer>> map = new HashMap<>();
    static Map<Integer, Map<Integer, Integer>> line = new HashMap<>();
    static int maxval = 0;
    static boolean[] visit;
    public static void init() throws Exception {
        N = Integer.parseInt(br.readLine());
        visit  = new boolean[N + 1];
        for(int i = 0; i <= N; ++i) {
            map.put(i,new ArrayList<Integer>());
            line.put(i, new HashMap<Integer,Integer>());
        }
        for(int i = 0; i < N - 1; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            line.get(node1).put(node2,val);
            line.get(node2).put(node1,val);
            map.get(node1).add(node2);
            map.get(node2).add(node1);
        }
    }

    public static int solve(int node) {
        visit[node] = true;
        int currMaxVal = 0;
        int currSecondMaxVal = 0;
        for(int i = 0; i < map.get(node).size(); ++i) {
            if(visit[map.get(node).get(i)]) continue;
            int currVal = solve(map.get(node).get(i)) + line.get(node).get(map.get(node).get(i));
            if(currVal > currMaxVal) {
                currSecondMaxVal = currMaxVal;
                currMaxVal = currVal;
            }
            else if (currVal > currSecondMaxVal)
                currSecondMaxVal = currVal;
        }
        maxval = Math.max(currMaxVal + currSecondMaxVal, maxval);
        return Math.max(currMaxVal, currSecondMaxVal);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve(1);
        System.out.println(maxval);
    }
}