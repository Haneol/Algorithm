package practice;

import java.util.*;
import java.io.*;

public class p04_1238 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); // 정점
        int m = Integer.parseInt(st.nextToken()); // 간선
        int x = Integer.parseInt(st.nextToken()); // 파티장소

        // 그래프 문제가.. 만약에 이런식으로, 인접그래프가 나온다!
        // 인덱스 = 정점
        // 그 인덱스의 값은 = 이 정점과 연결된 다음 정점들의 리스트야.
        // 1 : [2 3 4] -> 가변
        // 2 : 1 3
        // 3 : 1 4
        // 4 : 2
        // v
        // 정적

        List<Node>[] graph = new ArrayList[n + 1]; // 맞춰서 넣어주려고..
        for(int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st2.nextToken());
            int v2 = Integer.parseInt(st2.nextToken());
            int time = Integer.parseInt(st2.nextToken());

            graph[v1].add(new Node(v2, time));
        }
        // solve
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a.time, b.time);
        }); // time이 작은애가 우선순위가 높아
        int[] dist = new int[n + 1]; // 방문체크이자, 업데이트 되는 시간(누적시간, a->b
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            Arrays.fill(dist, Integer.MAX_VALUE);

            pq.offer(new Node(i, 0));
            dist[i] = 0;
            while(!pq.isEmpty()) {
                Node cur = pq.poll();

                // 왜? dist (최소) cur.time 이전에 계산한 누적시간
                if (dist[cur.v] < cur.time) continue;

                for(Node next : graph[cur.v]) { // a -> b, [k] a->b > a->k + k->b
                    int time = dist[cur.v] + next.time;

                    if(time < dist[next.v]) {
                        dist[next.v] = time;
                        pq.offer(new Node(next.v, time));
                    }
                }
            }

            int toParty = dist[x];
            Arrays.fill(dist, Integer.MAX_VALUE);
            pq.offer(new Node(x, 0));
            dist[x] = 0;
            while(!pq.isEmpty()) {
                Node cur = pq.poll();

                // 왜? dist (최소) cur.time 이전에 계산한 누적시간
                if (dist[cur.v] < cur.time) continue;

                for(Node next : graph[cur.v]) { // a -> b, [k] a->b > a->k + k->b
                    int time = dist[cur.v] + next.time;

                    if(time < dist[next.v]) {
                        dist[next.v] = time;
                        pq.offer(new Node(next.v, time));
                    }
                }
            }

            int fromParty = dist[i];

            maxTime = Math.max(maxTime, toParty + fromParty);
        }

        // output
        System.out.println(maxTime);

        br.close();
    }

    static class Node {
        int v;
        int time;

        Node(int v, int time) {
            this.v = v;
            this.time = time;
        }
    }
}
