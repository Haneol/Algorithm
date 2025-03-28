import java.io.*;
import java.util.*;

// 29분
public class b70_1644 {
    static boolean[] numbers;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        numbers = new boolean[n + 1];

        int idx = 0;
        List<Integer> li = new ArrayList<>();
        li.add(0);
        for (int i = 2; i <= n; i++) {
            if(numbers[i]) continue;

            idx = i;
            do {
                numbers[idx] = true;
            } while ((idx += i) <= n);

            li.add(i + li.get(li.size() - 1));
        }

        int start = 0;
        int end = 1;
        int count = 0;
        while(start < li.size() - 1 && end < li.size()) {
            int sum = li.get(end) - li.get(start);
            if (sum == n) {
                count++;
                start++;
            } else if (sum > n) {
                start++;
            } else {
                end++;
            }

            if (start == end) end++;
        }

        System.out.println(count);

        br.close();
    }
}
