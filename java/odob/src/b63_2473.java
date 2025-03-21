import java.io.*;
import java.util.*;

// 19분
public class b63_2473 {
    static long[] liquid;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        liquid = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            liquid[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(liquid);

        long[] res = new long[3];
        long absSum = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;

            while (left < right) {
                if (left == i) {
                    left++;
                } else if (right == i) {
                    right--;
                } else {
                    long cur = liquid[left] + liquid[right] + liquid[i];

                    if (Math.abs(cur) < absSum) {
                        absSum = Math.abs(cur);
                        res[0] = liquid[left];
                        res[1] = liquid[right];
                        res[2] = liquid[i];
                    }

                    if (cur <= 0) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        Arrays.sort(res);

        System.out.println(res[0] + " " + res[1] + " " + res[2]);

        br.close();
    }
}
