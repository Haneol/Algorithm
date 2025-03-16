import java.io.*;
import java.util.*;

// 32분
public class b58_11779 {
    static List<Node>[] city;
    static int[] busCost;
    static int[] visitCity;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        city = new ArrayList[n+1];
        busCost = new int[n+1];
        visitCity = new int[n+1];

        for(int i = 0; i < n+1; i++) {
            city[i] = new ArrayList<>();
            visitCity[i] = i;
        }

        for(int i = 0; i < m; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            city[start].add(new Node(end, cost));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int startCity = Integer.parseInt(st.nextToken());
        int endCity = Integer.parseInt(st.nextToken());


        // solve
        Arrays.fill(busCost, Integer.MAX_VALUE);
        busCost[startCity] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.cost));
        pq.offer(new Node(startCity, 0));

        while(!pq.isEmpty()){
            Node cur = pq.poll();

            if(cur.cost > busCost[cur.city]) continue;

            for(Node x : city[cur.city]) {
                int cost = busCost[cur.city] + x.cost;

                if(cost < busCost[x.city]) {
                    busCost[x.city] = cost;
                    pq.offer(new Node(x.city, cost));
                    visitCity[x.city] = cur.city;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(busCost[endCity]).append("\n");

        Deque<Integer> stack = new ArrayDeque<>();
        int k = endCity;
        stack.push(k);
        while(visitCity[k] != k) {
            stack.push(visitCity[k]);
            k = visitCity[k];
        }

        sb.append(stack.size()).append("\n");

        while(!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }

        System.out.println(sb);

        br.close();
    }

    static class Node {
        int city;
        int cost;

        Node(int city, int cost) {
            this.city = city;
            this.cost = cost;
        }
    }
}
