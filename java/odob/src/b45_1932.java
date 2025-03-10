import java.util.*;
import java.io.*;

public class b45_1932 {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());

        int[][] triangle = new int[n + 1][n + 1];
        for (int triangleRowIndex = 1; triangleRowIndex <= n; triangleRowIndex++) {
            StringTokenizer triangleInputTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int triangleColumnIndex = 1; triangleColumnIndex <= triangleRowIndex;
                    triangleColumnIndex++) {
                triangle[triangleRowIndex][triangleColumnIndex] = Integer.parseInt(triangleInputTokenizer.nextToken());
            }
        }

        int[][] dpTable = new int[n + 1][n + 1];
        for (int triangleRowIndex = 1; triangleRowIndex <= n; triangleRowIndex++) {
            for (int triangleColumnIndex = 1; triangleColumnIndex <= triangleRowIndex;
                    triangleColumnIndex++) {
                dpTable[triangleRowIndex][triangleColumnIndex] = Math.max(
                        dpTable[triangleRowIndex - 1][triangleColumnIndex] + triangle[triangleRowIndex][triangleColumnIndex],
                        dpTable[triangleRowIndex - 1][triangleColumnIndex - 1] + triangle[triangleRowIndex][triangleColumnIndex]
                );
            }
        }

        int maxSum = 0;
        for (int triangleColumnIndex = 1; triangleColumnIndex <= n; triangleColumnIndex++) {
            maxSum = Math.max(maxSum, dpTable[n][triangleColumnIndex]);
        }

        System.out.println(maxSum);

        bufferedReader.close();
    }
}
