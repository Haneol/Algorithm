import java.io.*;
import java.util.*;

public class b51_12865 {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] weights = new int[n];
        int[] values = new int[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st2 = new StringTokenizer(bufferedReader.readLine());

            weights[i] = Integer.parseInt(st2.nextToken());
            values[i] = Integer.parseInt(st2.nextToken());
        }

        int[][] dp = new int[n+1][k+1];

        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= k; w++) {
                if(weights[i-1] <= w) {
                    dp[i][w] = Math.max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }

        System.out.println(dp[n][k]);

        bufferedReader.close();
    }
}
