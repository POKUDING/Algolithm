import java.util.*;
import java.io.*;

class Main {
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

        if(cnt_balls[ball] != 0)
            return cnt_balls[ball];
        for(Integer next_ball : balls.get(ball)) {
            ++cnt;
            cnt += dfs(next_ball, cnt_balls, balls);
        }
        cnt_balls[ball] = cnt;
        return cnt;
    }

    public static void solution() {
        int notMiddleHeaby = 0;
        int notMiddleLight = 0;
        for(int i = 1; i <= N; ++i) {
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