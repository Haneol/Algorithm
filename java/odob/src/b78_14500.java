import java.io.*;
import java.util.*;

// 44분
public class b78_14500 {
    static int n, m;
    static int[][] paper;
    static int res;
    static int[][][] dir = {
            // 1. ㅡ
            {{0,0},{0,1},{0,2},{0,3}},
            {{0,0},{1,0},{2,0},{3,0}},
            // 2. ㅁ
            {{0,0},{0,1},{1,0},{1,1}},
            // 3. ㄱ
            {{0,0},{1,0},{2,0},{2,1}},
            {{0,0},{1,0},{2,0},{2,-1}},
            {{0,0},{1,0},{2,0},{0,1}},
            {{0,0},{1,0},{2,0},{0,-1}},
            {{0,0},{1,0},{0,1},{0,2}},
            {{0,0},{1,2},{0,1},{0,2}},
            {{0,0},{-1,0},{0,1},{0,2}},
            {{0,0},{-1,2},{0,1},{0,2}},
            // 4. 번개
            {{0,0},{1,0},{1,1},{2,1}},
            {{0,0},{1,0},{1,-1},{2,-1}},
            {{0,0},{0,1},{1,1}, {1,2}},
            {{0,0},{0,1},{-1,1},{-1,2}},
            // 5. ㅗ
            {{0,0},{0,1},{0,2},{1,1}},
            {{0,0},{0,1},{0,2},{-1,1}},
            {{0,0},{1,0},{2,0},{1,1}},
            {{0,0},{1,0},{2,0},{1,-1}}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        paper = new int[n][m];
        for(int i = 0; i < n; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++) {
                paper[i][j] = Integer.parseInt(input.nextToken());
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                solve(i,j);
            }
        }

        System.out.println(res);

        br.close();
    }

    static void solve(int y, int x) {
        int sum;
        boolean flag;
        for (int i = 0; i < 19; i++) {
            sum = 0;
            flag = false;
            for (int j = 0; j < 4; j++) {
                int dy = y + dir[i][j][0];
                int dx = x + dir[i][j][1];

                if (dy < 0 || dx < 0 || dx >= m || dy >= n) {
                    flag = true;
                    break;
                } else {
                    sum += paper[dy][dx];
                }
            }

            if (!flag) {
                res = Math.max(res, sum);
            }
        }
    }
}
