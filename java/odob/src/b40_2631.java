import java.util.*;
import java.io.*;

// 19분
public class b40_2631 {
    static int[] childrenList;
    static int[] dpTable;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());

        childrenList = new int[n];
        dpTable = new int[n];
        for (int childIndex = 0; childIndex < n; childIndex++) {
            childrenList[childIndex] = Integer.parseInt(bufferedReader.readLine());

            dpTable[childIndex] = 1;
            for(int previousChildIndex = 0; previousChildIndex < childIndex; previousChildIndex++) {
                if (childrenList[previousChildIndex] < childrenList[childIndex]) {
                    dpTable[childIndex] = Math.max(dpTable[previousChildIndex] + 1, dpTable[childIndex]);
                }
            }
        }

        int largestIncreasingSubsequenceCount = 0;
        for (int childIndex = 0; childIndex < n; childIndex++) {
            if(largestIncreasingSubsequenceCount < dpTable[childIndex]) {
                largestIncreasingSubsequenceCount = dpTable[childIndex];
            }
        }

        System.out.println(n - largestIncreasingSubsequenceCount);

        bufferedReader.close();
    }
}
