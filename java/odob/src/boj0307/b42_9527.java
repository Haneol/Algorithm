package boj0307;

import java.util.*;
import java.io.*;

// 40분, 힌트 참고
public class b42_9527 {
    static long[] totalSumByBinary = new long[64];

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        long a = Long.parseLong(baseInputTokenizer.nextToken());
        long b = Long.parseLong(baseInputTokenizer.nextToken());

        // 2의 지수 단위 누적합 계산
        totalSumByBinary[0] = 1;
        for (int exponent = 1; exponent < 64; exponent++) {
            totalSumByBinary[exponent] = totalSumByBinary[exponent - 1] * 2 + (1L << exponent);
        }

        long result = totalSum(b) - totalSum(a-1);
        System.out.println(result);

        bufferedReader.close();
    }

    static long totalSum(long number) {
        long count = number & 1L;
        for (int exponent = 63; exponent > 0; exponent--) {
            long currentBinaryNumber = (1L << exponent);
            if ((number & currentBinaryNumber) > 0) {
                count += totalSumByBinary[exponent - 1] + number - currentBinaryNumber + 1;
                number -= currentBinaryNumber;
            }
        }
        return count;
    }
}
