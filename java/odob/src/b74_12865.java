import java.io.*;
import java.util.*;

// 10분
public class b74_12865 {
    static int[][] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        dp = new int[n+1][k+1];
        for (int i = 1; i <= n; i++) {
            StringTokenizer item = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(item.nextToken());
            int v = Integer.parseInt(item.nextToken());

            for (int j = 0; j <= k; j++) {
                if(w <= j) {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-w] + v);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        System.out.println(dp[n][k]);

        br.close();
    }
}
