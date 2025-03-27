import java.io.*;
import java.util.*;

// 11분
public class b69_1715 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int x, y;
        for (int i = 0; i < n; i++) {
            x = Integer.parseInt(br.readLine());

            pq.add(x);
        }

        int res = 0;
        while(pq.size() > 1) {
            x = pq.poll();
            y = pq.poll();

            res += x + y;
            pq.add(x + y);
        }

        System.out.println(res);

        br.close();
    }
}
