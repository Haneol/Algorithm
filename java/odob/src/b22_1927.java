import java.io.*;
import java.util.*;

// 8분
public class b22_1927 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        StringBuilder sb = new StringBuilder();
        while(n-- > 0) {
            int num = Integer.parseInt(br.readLine());

            if(num == 0) {
                if(pq.isEmpty()) {
                    sb.append("0\n");
                } else {
                    sb.append(pq.poll()).append("\n");
                }
            } else {
                pq.add(num);
            }
        }

        System.out.println(sb);

        br.close();
    }
}
