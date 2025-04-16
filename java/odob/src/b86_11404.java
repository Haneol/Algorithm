import java.io.*;
import java.util.*;

// 32분
public class b86_11404 {
    static int[][] city;
    static int INF = 99999999;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        city = new int[n+1][n+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j) city[i][j] = INF;
            }
        }
        StringTokenizer st;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            city[a][b] = Math.min(city[a][b], c);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (city[i][j] > city[i][k] + city[k][j]) {
                        city[i][j] = city[i][k] + city[k][j];
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(city[i][j] >= INF){
                    sb.append(0);
                } else {
                    sb.append(city[i][j]);
                }
                sb.append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);

        br.close();
    }
}
