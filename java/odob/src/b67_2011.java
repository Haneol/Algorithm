import java.io.*;
import java.util.*;

// 43분
public class b67_2011 {
    static int[][] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        dp = new int[s.length()][27];
        dp[0][s.charAt(0) - '0'] = 1;
        for (int i = 1; i < s.length(); i++) {
            int x = s.charAt(i) - '0';

            for (int j = 1; j <= 26; j++) {
                if (dp[i - 1][j] == 0) continue;

                if (j * 10 + x <= 26) {
                    dp[i][j * 10 + x] = dp[i - 1][j];
                }

                dp[i][x] += dp[i - 1][j];
                dp[i][x] %= 1000000;
            }
        }

        int sum = 0;
        for (int i = 1; i <= 26; i++) {
            sum += dp[s.length() - 1][i];
            sum %= 1000000;
        }

        System.out.println(sum);

        br.close();
    }
}
