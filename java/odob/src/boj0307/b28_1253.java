package boj0307;

import java.util.*;
import java.io.*;

// 27분
public class b28_1253 {
    public static int[] numberList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        if(n <= 2) {
            System.out.println(0);
            return;
        }

        numberList = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            numberList[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(numberList);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int start = 0;
            int end = n-1;

            while(start < end) {
                int sum = numberList[start] + numberList[end];

                if(start == i) {
                    start++;
                } else if(end == i) {
                    end--;
                } else if(sum > numberList[i]) {
                    end--;
                } else if (sum < numberList[i]) {
                    start++;
                } else {
                    cnt++;
                    break;
                }
            }
        }

        System.out.println(cnt);

        br.close();
    }
}
