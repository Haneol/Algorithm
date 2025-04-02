import java.io.*;
import java.util.*;

// 11:40
public class b75_1799 {
    static int n;
    static int[][] chess;
    static int[][] tmp;
    static int res;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        chess = new int[n][n];
        tmp = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                chess[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean[][] visited = new boolean[n][n];
        bt(0, 0, visited);

        System.out.println(res);

        br.close();
    }

    static void bt(int y, int cnt, boolean[][] visited) {
        if(y == n) {

//            if(cnt == 8) {
//                for (int i = 0; i < n; i++) {
//                    for (int j = 0; j < n; j++) {
//                        System.out.print(tmp[i][j] + " ");
//                    }
//                    System.out.println();
//                }
//                System.out.println();
//            }

            res = Math.max(res, cnt);
            return;
        }

        boolean flag;
        for (int i = 0; i < (1 << n); i++) {
            flag = false;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0 && (visited[y][j] || chess[y][j] == 0)) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                for (int a = 0; a < n; a++) {
                    if ((i & (1 << a)) > 0) {
                        tmp[y][a] = 1;
                    }
                }

                bt(y + 1, cnt + Integer.bitCount(i), checkRow(y, i, visited));

                for (int a = 0; a < n; a++) {
                    tmp[y][a] = 0;
                }
            }
        }
    }

    static boolean[][] checkRow(int y, int x, boolean[][] visited) {
        boolean[][] newVisited = new boolean[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                newVisited[i][j] = visited[i][j];
            }
        }

        int x1, x2;
        for (int i = 0; i < n; i++) {
            if ((x & (1 << i)) > 0) {
                for (int j = 0; j < n; j++) {
                    x1 = i + (j - y);
                    x2 = i - (j - y);

                    if (x1 >= 0 && x1 < n) {
                        newVisited[j][x1] = true;
                    }

                    if (x2 >= 0 && x2 < n) {
                        newVisited[j][x2] = true;
                    }
                }
            }
        }

        return newVisited;
    }
}
