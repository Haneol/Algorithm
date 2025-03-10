package boj0307;

import java.util.*;
import java.io.*;

public class b48_14921 {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());

        StringTokenizer liquidInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        int[] liquidArray = new int[n];
        for(int liquidIndex = 0; liquidIndex < n; liquidIndex++) {
            liquidArray[liquidIndex] = Integer.parseInt(liquidInputTokenizer.nextToken());
        }
        Arrays.sort(liquidArray);

        int startPoint = 0;
        int endPoint = n-1;
        int nearestValue = Integer.MAX_VALUE;
        while(startPoint < endPoint) {
            int sum = liquidArray[startPoint] + liquidArray[endPoint];

            if(Math.abs(sum) < Math.abs(nearestValue)) {
                nearestValue = sum;
            }

            if (sum == 0) {
                break;
            } else if (sum < 0) {
                startPoint++;
            } else {
                endPoint--;
            }
        }

        System.out.println(nearestValue);

        bufferedReader.close();
    }
}
