import java.io.*;
import java.util.*;

// 11분
public class b82_9663 {
    static int n;
    static int[] chess;
    static int res;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        chess = new int[n + 1];
        bt(0);

        System.out.println(res);

        br.close();
    }

    static void bt(int depth) {
        if (depth >= n) {
            res++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (promising(depth, i)) {
                chess[depth + 1] = i;
                bt(depth + 1);
            }
        }
    }

    static boolean promising(int depth, int x) {
        for (int i = 1; i <= depth; i++) {
            if (chess[i] == x || Math.abs(depth + 1 - i) == Math.abs(x - chess[i])) {
                return false;
            }
        }
        return true;
    }
}
