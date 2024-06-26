import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N, M;
    static int[] knowTruth;
    static int[][] graph;
    static ArrayList<ArrayList<Integer>> parties = new ArrayList<ArrayList<Integer>>();

    static public void init() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        knowTruth = new int[N + 1];
        graph = new int[N + 1][N + 1];

        st = new StringTokenizer(br.readLine());
        int knowCnt = Integer.parseInt(st.nextToken());

        for(int i = 0; i < knowCnt; ++i)
            knowTruth[Integer.parseInt(st.nextToken())] = 1;

        for(int k = 0; k < M; ++k) {
            parties.add(new ArrayList<Integer>());
            st = new StringTokenizer(br.readLine());
            int partyPeople = Integer.parseInt(st.nextToken());
            int[] peoples = new int[partyPeople];
            for(int i = 0; i < partyPeople; ++i) {
                peoples[i] = Integer.parseInt(st.nextToken());
                parties.get(k).add(peoples[i]);
                for(int j = 0; j < i; ++j) {
                    graph[peoples[i]][peoples[j]] = 1;
                    graph[peoples[j]][peoples[i]] = 1;
                }
            }
        }
    }

    static public void bfs(int start, int[] visit) {
        Deque<Integer> deq = new ArrayDeque<>();
        visit[start] = 1;
        deq.add(start);

        while(!deq.isEmpty()) {
            int curr = deq.poll();

            for(int i = 1; i <= N; ++i) {
                if(graph[curr][i] == 1 && visit[i] != 1) {
                    visit[i] = 1;
                    knowTruth[i] = 1;
                    deq.add(i);
                } 
            }
        }
    }

    static public void addKnowPeople() {
        int[] visit = new int[N + 1];
        for(int i = 1; i < knowTruth.length; ++i) {
            if(knowTruth[i] == 1 && visit[i] != 1) {
                bfs(i, visit);
            }
        }
    }

    static public boolean checkCanTellParty(ArrayList<Integer> party) {
        for(int i = 0; i < party.size(); ++i) {
            if(knowTruth[party.get(i)] == 1)
                return false;
        }
        return true;
    }

    static public int cntCanTellParty() {
        int cnt = 0;
        for(int i = 0; i < M; ++i) {
            if(checkCanTellParty(parties.get(i)))
                ++cnt;
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        init();
        addKnowPeople();
        System.out.println(cntCanTellParty());
    }
}