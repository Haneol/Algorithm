import java.io.*;
import java.util.*;

// 41분
public class b84_2143 {
    static int[] A, B;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        B = new int[m];
        for (int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        List<Integer> sumA = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += A[j];
                sumA.add(sum);
            }
        }
        Collections.sort(sumA);

        List<Integer> sumB = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = i; j < m; j++) {
                sum += B[j];
                sumB.add(sum);
            }
        }
        Collections.sort(sumB);

        int start = 0, end = sumB.size() - 1;
        long res = 0;
        while (start < sumA.size() && end >= 0) {
            if (sumA.get(start) + sumB.get(end) == T) {
                long cnt1 = 0;
                long cnt2 = 0;
                int cmpA = sumA.get(start);
                int cmpB = sumB.get(end);
                while (start < sumA.size() && sumA.get(start) == cmpA) {
                    cnt1++;
                    start++;
                }
                while (end >= 0 && sumB.get(end) == cmpB) {
                    cnt2++;
                    end--;
                }
                res += cnt1 * cnt2;
            } else if (sumA.get(start) + sumB.get(end) > T) {
                end--;
            } else {
                start++;
            }
        }

        System.out.println(res);

        br.close();
    }
}
