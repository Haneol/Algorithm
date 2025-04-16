import java.io.*;
import java.util.*;

// 51분
public class b85_17281 {
    static int n;
    static int[][] baseball;
    static int[] permArr = new int[9];
    static boolean[] visited = new boolean[9];
    static int res;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        baseball = new int[n][9];

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                baseball[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        permArr[3] = 0;
        visited[0] = true;
        perm(0);
        System.out.println(res);

        br.close();
    }

    static void perm(int depth) {
        if (depth == 9) {
            calc();
            return;
        }

        if(depth == 3) {
            perm(depth + 1);
            return;
        }

        for (int i = 0; i < 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                permArr[depth] = i;
                perm(depth + 1);
                visited[i] = false;
            }
        }
    }

    static void calc() {
        int player = 0;
        int out = 0;
        int inning = 0;
        int score = 0;
        boolean b1 = false, b2 = false, b3 = false;
        while (inning < n) {
            int tmp = baseball[inning][permArr[player]];
            if (tmp == 0) {
                if (++out >= 3) {
                    inning++;
                    out = 0;
                    b1 = b2 = b3 = false;
                }
            } else if (tmp == 1) {
                if (b3) score++;
                b3 = b2;
                b2 = b1;
                b1 = true;
            } else if (tmp == 2) {
                if (b3) score++;
                if (b2) score++;
                b3 = b1;
                b2 = true;
                b1 = false;
            } else if (tmp == 3) {
                if (b3) score++;
                if (b2) score++;
                if (b1) score++;
                b3 = true;
                b2 = false;
                b1 = false;
            } else {
                if (b3) score++;
                if (b2) score++;
                if (b1) score++;
                score++;
                b1 = b2 = b3 = false;
            }
            player = (player + 1) % 9;
        }

        res = Math.max(res, score);
    }
}
