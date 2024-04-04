import java.util.*;
import javafx.util.Pair;

class Solution {
    public int solution(int[] priorities, int location) {
        int process_idx = priorities.length - 1;
        Queue<Pair<Integer,Integer>> que = new LinkedList<>();
        for(int i = 0; i < priorities.length; ++i) {
            que.add(new Pair<Integer,Integer>(priorities[i],i));
        }
        Arrays.sort(priorities);
        // Arrays.stream(priorities).forEach(System.out::println);
        // System.out.println(que);
        while(!que.isEmpty()) {
            var process = que.remove();
            if(process.getKey().equals(priorities[process_idx])) {
                --process_idx;
                if(process.getValue() == location)
                    return priorities.length - process_idx - 1;
            } else
                que.add(process);
        }
        return 0;
    }
}