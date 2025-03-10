package boj0307;

import java.io.*;
import java.util.*;

// 55분, XX
public class b11_13549 {
    public static int[] location = new int[100001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Deque<Integer> q = new LinkedList<>();

        q.addLast(n);
        location[n] = 1;
        while (!q.isEmpty()) {
            int x = q.pollFirst();

            for(int d = 0; d < 3; d++) {
                int dx = nextLocation(x, d);

                if(dx < 0 || dx > 100000) continue;

                if(location[dx] == 0) {
                    if(d == 0) {
                        q.addFirst(dx);
                        location[dx] = location[x];
                    } else {
                        q.addLast(dx);
                        location[dx] = location[x] + 1;
                    }
                }

                if(dx == k) {
                    System.out.println(location[dx] - 1);
                    return;
                }
            }
        }

        br.close();
    }

    public static int nextLocation(int x, int d) {
        if(d == 0) {
            return x * 2;
        } else if (d == 1) {
            return x - 1;
        } else {
            return x + 1;
        }
    }
}
