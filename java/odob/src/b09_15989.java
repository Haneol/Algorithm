import java.io.*;

// 49분, A
public class b09_15989 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        int[] input = new int[T];
        int maxInput = 0;
        for(int i = 0; i < T; i++) {
            input[i] = Integer.parseInt(br.readLine());
            if(input[i] > maxInput) {
                maxInput = input[i];
            }
        }

        int[][] dp = new int[maxInput + 1][4];
        dp[1][1] = 1; // 1
        dp[2][1] = 1; // 1+1
        dp[2][2] = 1; // 2
        dp[3][1] = 1; // 1+1+1
        dp[3][2] = 1; // 1+2
        dp[3][3] = 1; // 3

        for(int i = 4; i <= maxInput; i++) {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1] + dp[i-2][2];
            dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
        }

        StringBuilder sb = new StringBuilder();
        for(int i : input) {
            sb.append(dp[i][1] + dp[i][2] + dp[i][3]).append("\n");
        }

        System.out.println(sb);

        br.close();
    }
}
