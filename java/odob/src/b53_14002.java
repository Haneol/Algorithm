import java.io.*;
import java.util.*;

// 14분
public class b53_14002 {
    static int[] numbers;
    static int[] lis;
    static int[] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        numbers = new int[n];
        lis = new int[n];
        dp = new int[n];
        int size = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());

            int pos = Arrays.binarySearch(lis, 0, size, numbers[i]);

            if(pos < 0) {
                pos = -(pos + 1);
            }

            lis[pos] = numbers[i];
            if(pos == size) size++;

            dp[i] = pos + 1;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(size).append("\n");

        Deque<Integer> stack = new ArrayDeque<>();
        for(int i = n - 1; i >= 0; i--) {
            if(size == dp[i]) {
                stack.push(numbers[i]);
                size--;
            }
        }

        while(!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }

        System.out.println(sb);

        br.close();
    }
}
