import java.util.*;
import java.io.*;

class Main {
    static int K, V, E;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Integer>[] node;
    static int[] color;

    public static void readInput() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        node = new ArrayList[V + 1];
        for(int i = 0; i <= V; ++i)
            node[i] = new ArrayList<>();
        color = new int[V + 1];
        for(int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            node[u].add(v);
            node[v].add(u);
        }
    }

    public static boolean bfs(Integer start) {
        Queue<int[]> que = new LinkedList<>();

        que.add(new int[]{start , 1});
        while(!que.isEmpty()) {
            int[] curr = que.remove();
            color[curr[0]] = curr[1];
            for(Integer next : node[curr[0]]) {
                if(color[next] == curr[1])
                    return false;
                if(color[next] == 0)
                    que.add(new int[]{next, curr[1] == 1 ? 2 : 1});
            }
        }
        return true;
    }

    public static boolean solution() throws Exception {
        readInput();
        for(int i = 1; i <= V; ++i) {
            if(color[i] == 0 && !bfs(i))
                return false;
        }
        return true;
    }

    public static void main (String[] args) throws Exception{
        K = Integer.parseInt(br.readLine());
        for(int i = 0; i < K; ++i) {
            if(solution())
                System.out.println("YES");
            else
                System.out.println("NO");
        }

    }
}