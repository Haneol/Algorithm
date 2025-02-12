import java.io.*;
import java.util.*;

// 16분
public class b17_2493 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer towerInput = new StringTokenizer(br.readLine());

        Deque<Integer[]> towerStack = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            towerStack.push(new Integer[]{i, Integer.parseInt(towerInput.nextToken())});
        }

        Deque<Integer[]> stack = new ArrayDeque<>();

        int[] answer = new int[n];
        while (!towerStack.isEmpty()) {
            Integer[] current = towerStack.pop();
            while (!stack.isEmpty() && stack.peek()[1] < current[1]) {
                answer[stack.peek()[0]] = current[0] + 1;
                stack.pop();
            }
            stack.push(current);
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            sb.append(answer[i]).append(" ");
        }

        System.out.println(sb);

        br.close();
    }
}
