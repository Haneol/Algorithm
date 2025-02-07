import java.io.*;
import java.util.*;

public class b07_25757 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        char game = st.nextToken().charAt(0);

        Map<String, Boolean> map = new HashMap<>();

        for(int i = 0; i < n; i++){
            String player = br.readLine();

            if(!map.containsKey(player)){
                map.put(player, true);
            }
        }

        int requirePlayer = 1;
        switch (game) {
            case 'Y':
                requirePlayer = 1;
                break;
            case 'F':
                requirePlayer = 2;
                break;
            case 'O':
                requirePlayer = 3;
                break;
            default:
                break;
        }

        System.out.println(map.size() / requirePlayer);

        br.close();
    }
}
