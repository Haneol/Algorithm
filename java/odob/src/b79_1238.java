import java.io.*;
import java.util.*;

// 20분
public class b79_1238 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        List<Node>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(input.nextToken());
            int b = Integer.parseInt(input.nextToken());
            int t = Integer.parseInt(input.nextToken());

            graph[a].add(new Node(b, t));
        }

        PriorityQueue<Node> q = new PriorityQueue<>(Comparator.comparingInt(a -> a.time));
        int[][] dist = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++) {
            q.offer(new Node(i, 0));
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            dist[i][i] = 0;

            while(!q.isEmpty()) {
                Node cur = q.poll();

                if(cur.time > dist[i][cur.city]) continue;

                for (Node next : graph[cur.city]) {
                    int newTime = next.time + dist[i][cur.city];

                    if (newTime < dist[i][next.city]) {
                        dist[i][next.city] = newTime;
                        q.offer(new Node(next.city, newTime));
                    }
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= n; i++) {
            res = Math.max(res, dist[i][x] + dist[x][i]);
        }

        System.out.println(res);

        br.close();
    }

    static class Node {
        int city, time;

        Node(int city, int time) {
            this.city = city;
            this.time = time;
        }
    }
}
