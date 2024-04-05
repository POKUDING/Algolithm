import java.util.*;
import java.io.*;
import java.lang.*;
import javafx.util.Pair;

class Main {
    static final int INF = Integer.MAX_VALUE;
    static int V, E, K;
    static int[][] arr;
    static boolean[] visit;

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        K = Integer.parseInt(br.readLine());

        arr = new int[V][V];
        visit = new boolean[V][V];

        for(int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            arr[u][v] = w;
        }
    }

    public static void dijkstra() {
        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue<>();

        pq.add(new Pair<Integer,Integer>(0, K));
        while(!pq.isEmpty()) {
            Pair<Integer,Integer> curr = pq.poll();
        }
    }
    public static void main (String[] args) throws Exception{
        init();
    }
}