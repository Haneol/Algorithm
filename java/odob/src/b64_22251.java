import java.io.*;
import java.util.*;

// 1시간 4분
public class b64_22251 {
    static int N, K, X, P;
    static int count;
    static int[][] diff = {
            {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
            {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
            {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
            {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
            {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
            {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
            {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
            {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
            {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
            {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
    };
    static int[] currentFloor;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); // 층
        K = Integer.parseInt(st.nextToken()); // 디스플레이 자리수
        P = Integer.parseInt(st.nextToken()); // 최대 반전시킬 개수
        X = Integer.parseInt(st.nextToken()); // 실제 멈춘 층
        currentFloor = new int[K];

        int tmp = 0;
        do {
            currentFloor[K - 1 - tmp++] = X % 10;
        } while((X /= 10) > 0);

        bt(0,0,0);
        System.out.println(count - 1);

        br.close();
    }

    static void bt(int depth, int diffLed, int floor) {
        if(depth == K) {
            if(diffLed <= P && floor > 0 && floor <= N) {
                count++;
            }
            return;
        }

        for(int i = 0; i <= 9; i++) {
            if (diffLed + diff[currentFloor[depth]][i] <= P) {
                bt(depth + 1, diffLed + diff[currentFloor[depth]][i], floor * 10 + i);
            }
        }
    }
}
