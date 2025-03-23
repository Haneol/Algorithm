import java.io.*;
import java.util.*;

// 26분
public class b65_1939 {
    static List<Node>[] graph;
    static int[] dist;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        dist = new int[n+1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        int x, y, weight;
        for (int i = 0; i < m; i++) {
            StringTokenizer bridgeInput = new StringTokenizer(br.readLine());

            x = Integer.parseInt(bridgeInput.nextToken());
            y = Integer.parseInt(bridgeInput.nextToken());
            weight = Integer.parseInt(bridgeInput.nextToken());

            graph[x].add(new Node(y, weight));
            graph[y].add(new Node(x, weight));
        }

        StringTokenizer factoryInput = new StringTokenizer(br.readLine());
        int factoryA = Integer.parseInt(factoryInput.nextToken());
        int factoryB = Integer.parseInt(factoryInput.nextToken());

        // solve
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b) -> {
            return Integer.compare(b.weight, a.weight);
        });

        pq.offer(new Node(factoryA, 0));
        dist[factoryA] = 0;
        while(!pq.isEmpty()) {
            Node cur = pq.poll();

            if(cur.weight < dist[cur.island]) continue;

            for(Node next : graph[cur.island]) {
                int w = dist[cur.island] == 0 ? next.weight : Math.min(dist[cur.island], next.weight);

                if(dist[next.island] < w) {
                    dist[next.island] = w;
                    pq.offer(next);
                }
            }
        }

        System.out.println(dist[factoryB]);

        br.close();
    }

    static class Node {
        int island;
        int weight;

        Node(int island, int weight) {
            this.island = island;
            this.weight = weight;
        }
    }
}
