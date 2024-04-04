import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        ArrayList<String[]> message= new ArrayList<>();
        Map<String,String> map = new HashMap<>();
        for(int i = 0; i < record.length; ++i) {
            String[] splitRecord = record[i].split(" ");
            if(splitRecord[0].equals("Enter") || splitRecord[0].equals("Change"))
                map.put(splitRecord[1], splitRecord[2]);
            if(!splitRecord[0].equals("Change"))
                message.add(splitRecord);
        //              for (Map.Entry<String, String> entry : map.entrySet()) {
        //     String key = entry.getKey();
        //     String value = entry.getValue();
        //     System.out.println(key + " " + value);
        // }
        }
        // message.stream().forEach(msg->{Arrays.stream(msg).forEach(System.out::println);});
        return resultBuilder(message, map);
    }
    private String[] resultBuilder(ArrayList<String[]> message
                                  , Map<String,String> map) {
        ArrayList<String> rtn = new ArrayList<>();
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < message.size(); ++i) {
            sb.append(map.get(message.get(i)[1]))
                .append("님이 ");
            if(message.get(i)[0].equals("Enter"))
                sb.append("들어왔습니다.");
            else
                sb.append("나갔습니다.");
            // System.out.println(sb.toString());
            rtn.add(sb.toString());
            sb.setLength(0);
        }
        return rtn.toArray(new String[rtn.size()]);
    }
}