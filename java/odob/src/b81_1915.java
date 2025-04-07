import java.io.*;
import java.util.*;

// 12분
public class b81_1915 {
    static int[][] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        dp = new int[n + 1][m + 1];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 1; j <= m; j++) {
                if (input[j-1] == '1') {
                    dp[i][j] = Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    res = Math.max(res, dp[i][j]);
                }
            }
        }

        System.out.println(res*res);

        br.close();
    }
}
