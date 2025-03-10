package boj0307;

import java.util.*;
import java.io.*;

// 31
public class b47_2143 {
    static int T, n, m;
    static int[] A, B;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(bufferedReader.readLine());
        n = Integer.parseInt(bufferedReader.readLine());
        A = new int[n + 1];
        StringTokenizer inputATokenizer = new StringTokenizer(bufferedReader.readLine());
        for(int aIndex = 1; aIndex <= n; aIndex++) {
            A[aIndex] = A[aIndex - 1] + Integer.parseInt(inputATokenizer.nextToken());
        }
        m = Integer.parseInt(bufferedReader.readLine());
        B = new int[m + 1];
        StringTokenizer inputBTokenizer = new StringTokenizer(bufferedReader.readLine());
        for(int bIndex = 1; bIndex <= m; bIndex++) {
            B[bIndex] = B[bIndex - 1] + Integer.parseInt(inputBTokenizer.nextToken());
        }

        List<Integer> sumA = new ArrayList<>();
        List<Integer> sumB = new ArrayList<>();
        for (int aRightIndex = 1; aRightIndex <= n; aRightIndex++) {
            for (int aLeftIndex = 0; aLeftIndex < aRightIndex; aLeftIndex++) {
                sumA.add(A[aRightIndex] - A[aLeftIndex]);
            }
        }

        for (int bRightIndex = 1; bRightIndex <= m; bRightIndex++) {
            for (int bLeftIndex = 0; bLeftIndex < bRightIndex; bLeftIndex++) {
                sumB.add(B[bRightIndex] - B[bLeftIndex]);
            }
        }

        Collections.sort(sumA);
        Collections.sort(sumB);

        int count = 0;
        int left = 0;
        int right = sumB.size() - 1;
        while(left < sumA.size() && right >= 0) {
            if (sumA.get(left) + sumB.get(right) == T) {
                int currentA = sumA.get(left);
                int currentB = sumB.get(right);
                int countA = 0;
                int countB = 0;

                while (left < sumA.size() && currentA == sumA.get(left)) {
                    left++;
                    countA++;
                }

                while (right >= 0 && currentB == sumB.get(right)) {
                    right--;
                    countB++;
                }

                count = countA * countB;
            } else if (sumA.get(left) + sumB.get(right) < T) {
                left++;
            } else {
                right--;
            }
        }

        System.out.println(count);

        bufferedReader.close();
    }
}
