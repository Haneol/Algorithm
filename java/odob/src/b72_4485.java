import java.io.*;
import java.util.*;

// 18분
public class b72_4485 {
    static int[][] board = new int[125][125];
    static int[][] dist = new int[125][125];
    static Node[] dir = {
            new Node(0, 1, 0),
            new Node(0, -1, 0),
            new Node(1, 0, 0),
            new Node(-1, 0, 0),
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.weight));
        StringBuilder sb = new StringBuilder();

        int tc = 1;
        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            pq.offer(new Node(0,0,board[0][0]));
            for(int[] row : dist) {
                Arrays.fill(row, Integer.MAX_VALUE);
            }
            dist[0][0] = board[0][0];

            while(!pq.isEmpty()) {
                Node cur = pq.poll();

                if (cur.weight < dist[cur.y][cur.x]) continue;

                for (int d = 0; d < 4; d++) {
                    int dy = cur.y + dir[d].y;
                    int dx = cur.x + dir[d].x;

                    if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;

                    int nextWeight = board[dy][dx] + cur.weight;
                    if (nextWeight < dist[dy][dx]) {
                        dist[dy][dx] = nextWeight;
                        pq.offer(new Node(dy, dx, nextWeight));
                    }
                }
            }

            sb.append("Problem ").append(tc++).append(": ").append(dist[n-1][n-1]).append('\n');
        }

        System.out.println(sb);

        br.close();
    }

    static class Node {
        int y, x, weight;

        Node(int y, int x, int weight) {
            this.y = y;
            this.x = x;
            this.weight = weight;
        }
    }
}
