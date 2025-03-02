import java.io.*;
import java.util.*;

// 22분, 힌트 참고, 시간초과, 틀림
public class b29_1806 {
    public static int[] numList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        numList = new int[n+1];

        StringTokenizer numListInput = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            numList[i] = numList[i-1] + Integer.parseInt(numListInput.nextToken());
        }

        int start = 0;
        int end = 1;
        int minLength = 1000000;
        while (start <= n && end <= n) {
            int sum = numList[end] - numList[start];
            if (sum >= s) {
                minLength = Math.min(minLength, end - start);
                if(start == end) end++;
                start++;
            } else {
                end++;
            }
        }

        if(minLength == 1000000) {
            System.out.println(0);
        } else {
            System.out.println(minLength);
        }

        br.close();
    }
}
