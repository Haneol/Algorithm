package pracPermNComb;

import java.io.*;
import java.util.*;

// 20분
public class p01_1182 {
    static int n, s;
    static int combinationSubListEqualSCount;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        n = Integer.parseInt(baseInputTokenizer.nextToken());
        s = Integer.parseInt(baseInputTokenizer.nextToken());

        StringTokenizer permutationInputTokenizer = new StringTokenizer(bufferedReader.readLine());

        int[] permutationArray = new int[n];
        for (int permutationArrayIndex = 0; permutationArrayIndex < n; permutationArrayIndex++) {
            permutationArray[permutationArrayIndex] = Integer.parseInt(
                    permutationInputTokenizer.nextToken());
        }

        combination(permutationArray);

        System.out.println(combinationSubListEqualSCount);

        bufferedReader.close();
    }

    static void combination(int[] originalArray) {
        int originalArrayLength = originalArray.length;

        for (int combinationIndex = 1; combinationIndex < (1 << originalArrayLength); combinationIndex++) {
            List<Integer> combinationArray = new ArrayList<>();

            for (int originalArrayIndex = 0; originalArrayIndex < originalArrayLength; originalArrayIndex++) {
                if((combinationIndex & (1 << originalArrayIndex)) > 0) {
                    combinationArray.add(originalArray[originalArrayIndex]);
                }
            }

            int combinationArrayItemSum = 0;
            for(int combinationArrayItem : combinationArray) {
                combinationArrayItemSum += combinationArrayItem;
            }

            if(combinationArrayItemSum == s) {
                combinationSubListEqualSCount++;
            }
        }
    }
}
