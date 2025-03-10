package boj0307;

import java.io.*;
import java.util.*;


// 22분, 힌트 참고함
public class b23_2668 {
    public static int[] arr;
    public static boolean[] visited;
    public static PriorityQueue<Integer> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n + 1];
        visited = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        // 사이클이 발생하는 경우를 찾고,
        // 이 경우에 대한 최대의 사이클 개수를 센다.
        for(int i = 1; i <= n; i++){
            visited[i] = true;
            dfs(i, i);
            visited[i] = false;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(pq.size()).append("\n");
        for(int num : pq){
            sb.append(num).append("\n");
        }

        System.out.println(sb);

        br.close();
    }

    public static void dfs(int cur, int start) {
        if(arr[cur] == start) {
            pq.add(start);
        } else if (!visited[arr[cur]]){
            visited[arr[cur]] = true;
            dfs(arr[cur], start);
            visited[arr[cur]] = false;
        }
    }
}
