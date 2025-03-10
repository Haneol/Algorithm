import java.io.*;
import java.util.*;

public class b50_9251 {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String str1 = bufferedReader.readLine();
        String str2 = bufferedReader.readLine();

        int n = str1.length();
        int m = str2.length();
        int[][] dp = new int[n+1][m+1];

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        System.out.println(dp[n][m]);

        bufferedReader.close();
    }
}
