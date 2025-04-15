import java.io.*;
import java.util.*;

// 43분
public class b83_1202 {
    static Node[] jewelry;
    static int[] bags;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        jewelry = new Node[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());

            jewelry[i] = new Node(
                    Integer.parseInt(input.nextToken()),
                    Integer.parseInt(input.nextToken()));
        }
        Arrays.sort(jewelry, Comparator.comparingInt(a -> a.weight));

        bags = new int[k];
        for (int i = 0; i < k; i++) {
            bags[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(bags);

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> Integer.compare(b.value, a.value));

        int idx = 0;
        long res = 0;
        for (int i = 0; i < k; i++) {
            while(idx < n && jewelry[idx].weight <= bags[i]) {
                pq.offer(jewelry[idx]);
                idx++;
            }

            if(!pq.isEmpty()) {
                res += pq.poll().value;
            }
        }

        System.out.println(res);

        br.close();
    }

    static class Node {
        int weight, value;

        Node(int weight, int value) {
            this.weight = weight;
            this.value = value;
        }
    }
}
