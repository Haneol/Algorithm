import java.io.*;
import java.util.*;

// 40분, 시간초과, X
public class b34_1976 {
    public static int n, m;
    public static boolean[][] cityConnection;
    public static int[] tripPlanArray;

    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        cityConnection = new boolean[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            StringTokenizer cityConnectionTokenizer = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                cityConnection[i][j] = cityConnectionTokenizer.nextToken().equals("1");
            }
        }

        tripPlanArray = new int[m];
        StringTokenizer tripPlanTokenizer = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            tripPlanArray[i] = Integer.parseInt(tripPlanTokenizer.nextToken());
        }

        visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.offer(tripPlanArray[0]);
        visited[tripPlanArray[0]] = true;

        while(!q.isEmpty()) {
            int current = q.poll();

            for(int d = 1; d <= n; d++) {
                if(cityConnection[current][d] && !visited[d]) {
                    visited[d] = true;
                    q.offer(d);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if(!visited[tripPlanArray[i]]) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");

        br.close();
    }
}
