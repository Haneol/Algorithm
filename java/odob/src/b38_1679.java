import java.io.*;
import java.util.*;

// 15분
public class b38_1679 {
    static int[] visitedTime = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(baseInputTokenizer.nextToken());
        int k = Integer.parseInt(baseInputTokenizer.nextToken());

        Queue<Integer> q = new LinkedList<>();

        q.offer(n);
        visitedTime[n] = 1;

        while (!q.isEmpty()) {
            int currentLocation = q.poll();

            if(currentLocation == k) {
                System.out.println(visitedTime[currentLocation] - 1);
                return;
            }

            // 순간이동
            int nextLocation = currentLocation * 2;
            if(nextLocation <= 100000 && visitedTime[nextLocation] == 0) {
                q.offer(nextLocation);
                visitedTime[nextLocation] = visitedTime[currentLocation] + 1;
            }

            // 뒤로 이동
            nextLocation = currentLocation - 1;
            if(nextLocation >= 0 && visitedTime[nextLocation] == 0) {
                q.offer(nextLocation);
                visitedTime[nextLocation] = visitedTime[currentLocation] + 1;
            }

            // 앞으로 이동
            nextLocation = currentLocation + 1;
            if(nextLocation <= 100000 && visitedTime[nextLocation] == 0) {
                q.offer(nextLocation);
                visitedTime[nextLocation] = visitedTime[currentLocation] + 1;
            }
        }

        br.close();
    }
}
