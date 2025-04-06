import java.io.*;
import java.util.*;

// 4시간, 힌트 참고
public class b75_1799 {
    static int n;
    static int[][] chess;
    static int res1, res2;
    static Deque<int[]> visited = new ArrayDeque<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        chess = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                chess[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        bt1(0,0, 0);
        bt2(0,0, 0);

        System.out.println(res1 + res2);

        br.close();
    }

    static void bt1(int y, int x, int cnt) {
        if (y >= n - 1 && x >= n - 1) {
            return;
        }

        for (int i = y; i < n; i++) {
            for (int j = i % 2; j < n; j+=2) {
                if (check(i, j) || chess[i][j] == 0) continue;

                res1 = Math.max(res1, cnt + 1);
                visited.offerLast(new int[]{i, j});
                bt1(i, j, cnt + 1);
                visited.pollLast();
            }
        }
    }

    static void bt2(int y, int x, int cnt) {
        if (y >= n - 1 && x >= n - 2) {
            return;
        }

        for (int i = y; i < n; i++) {
            for (int j = (i + 1) % 2; j < n; j+=2) {
                if (check(i, j) || chess[i][j] == 0) continue;

                res2 = Math.max(res2, cnt + 1);
                visited.offerLast(new int[]{i, j});
                bt2(i, j, cnt + 1);
                visited.pollLast();
            }
        }
    }

    static boolean check(int y, int x) {
        int x1, x2;

        for (int[] pos : visited) {
            if (Math.abs(pos[0] - y) == Math.abs(pos[1] - x)) {
                return true;
            }
        }

        return false;
    }
}
