package practice;

import java.util.*;
import java.io.*;

public class p03_1253 {
    static int[] numberList;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());
        StringTokenizer numberListInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        numberList = new int[n];
        for(int numberIndex = 0; numberIndex < n; numberIndex++) {
            numberList[numberIndex] = Integer.parseInt(numberListInputTokenizer.nextToken());
        }

        // 음수도 되는구나 -> 혹시 시간초과 날 일 없나? 타입 int -> long 필요 없나?
        // 정렬이 안되어있겠네
        // n^2까지는 되겠다 일단..

        // 투포인터 쓰면 되겠다
        int left, right;
        int countGoodNumber = 0;
        for(int numberIndex = 0; numberIndex < n; numberIndex++) {
            left = 0;
            right = n - 1;

            while(left < right) {
                int sum = numberList[left] + numberList[right];

                if(left == numberIndex) {
                    left++;
                } else if (right == numberIndex) {
                    right--;
                } else if(sum == numberList[numberIndex]) {
                    countGoodNumber++;
                    break;
                } else if(sum < numberList[numberIndex]) { // 커져야 해 값이 -> 늘려야지(left만 늘릴 수 있어)
                    left++;
                } else {
                    right--;
                }
            }
        }

        System.out.println(countGoodNumber);
    }
}
