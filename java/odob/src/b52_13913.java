import java.util.*;
import java.io.*;

// 29분
public class b52_13913 {
    static int MAX = 100000;
    static int[] location = new int[MAX + 1];
    static int[] prev = new int[MAX + 1];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Arrays.fill(prev, -1);

        Queue<Integer> q = new LinkedList<>();
        location[n] = 1;
        q.offer(n);

        while(!q.isEmpty()) {
            int cur = q.poll();

            if (cur == k) {
                System.out.println(location[cur] - 1);
                break;
            }

            for (int d = 0; d < 3; d++) {
                int next = nextLoc(cur, d);

                if (next < 0 || next > MAX) continue;

                if (location[next] == 0) {
                    location[next] = location[cur] + 1;
                    prev[next] = cur;
                    q.offer(next);
                }
            }
        }

        Deque<Integer> route = new ArrayDeque<>();
        int i = k;
        route.push(k);
        while(prev[i] != -1) {
            route.push(prev[i]);
            i = prev[i];
        }

        StringBuilder sb = new StringBuilder();
        while(!route.isEmpty()) {
            sb.append(route.pop()).append(" ");
        }

        System.out.print(sb);

        br.close();
    }

    static int nextLoc(int cur, int d) {
        switch(d) {
            case 0:
                return cur*2;
            case 1:
                return cur-1;
            case 2:
                return cur+1;
        }
        return -1;
    }
}
