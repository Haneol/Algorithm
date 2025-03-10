package boj0307;

import java.io.*;
import java.util.*;

public class b44_2559 {
    static int[] degreeCumulativeSum;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        int n = Integer.parseInt(baseInputTokenizer.nextToken());
        int k = Integer.parseInt(baseInputTokenizer.nextToken());

        StringTokenizer degreeInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        degreeCumulativeSum = new int[n+1];
        for(int degreeIndex = 1; degreeIndex <= n; degreeIndex++) {
            degreeCumulativeSum[degreeIndex] = degreeCumulativeSum[degreeIndex - 1] + Integer.parseInt(degreeInputTokenizer.nextToken());
        }

        int maxDegreeSum = Integer.MIN_VALUE;
        for(int degreeIndex = k; degreeIndex <= n; degreeIndex++) {
            maxDegreeSum = Math.max(maxDegreeSum,
                    degreeCumulativeSum[degreeIndex] - degreeCumulativeSum[degreeIndex - k]);
        }

        System.out.println(maxDegreeSum);

        bufferedReader.close();
    }
}
