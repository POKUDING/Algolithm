import java.util.*;
import java.io.*;

class Main {
    static final int MAX = 1000;
    static ArrayList<Set<Integer>> heavy;
    static ArrayList<Set<Integer>> light;
    // 중복된 입력을 받으면 정답이 틀림 ArryList -> Set으로 변경
    static int[] cnt_heavyball;
    static int[] cnt_lightball;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, M;

    public static void init() throws Exception{
        heavy = new ArrayList<>();
        light = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        cnt_heavyball = new int[N + 1];
        cnt_lightball = new int[N + 1];

        for(int i = 0; i <= N; ++i){
            heavy.add(new HashSet<Integer>());
            light.add(new HashSet<Integer>());
        }

        for (int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            int heavyBall = Integer.parseInt(st.nextToken());
            int lightBall = Integer.parseInt(st.nextToken());
            light.get(heavyBall).add(lightBall);
            heavy.get(lightBall).add(heavyBall);
        }

    }

    public static int dfs(int ball, int[] cnt_balls, ArrayList<Set<Integer>> balls) {
        int cnt = 0;

        // System.out.println("dfs start ball: " + ball);
        if(cnt_balls[ball] != MAX)
            return cnt_balls[ball];
        for(Integer next_ball : balls.get(ball)) {
            // if문처리를 안해주면 방문했던 노드 추가로 방문하게됨 갯수 증가(1 > 2, 1 > 3, 3 > 2 시에 1이 3개보다 큰걸로 됨)
            if(cnt_balls[next_ball] == MAX) {
                ++cnt;
                cnt += dfs(next_ball, cnt_balls, balls);
            }
        }
        cnt_balls[ball] = cnt;
        // System.out.println("ball: " + ball + " cnt: " + cnt);
        return cnt;
    }

    public static void solution() {
        int notMiddleHeaby = 0;
        int notMiddleLight = 0;
        for(int i = 1; i <= N; ++i) {
            Arrays.fill(cnt_heavyball, MAX);
            Arrays.fill(cnt_lightball, MAX);
            //Array 초기화를 매번 해줘야함
            if(dfs(i, cnt_heavyball, heavy) > N / 2)
                ++notMiddleHeaby;
            else if (dfs(i, cnt_lightball, light) > N / 2)
                ++notMiddleLight;
        }
        System.out.println(notMiddleHeaby + notMiddleLight);
    }

    public static void main(String[] args) throws Exception {
        init();
        solution();
    }
}