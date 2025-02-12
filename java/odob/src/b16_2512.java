import java.io.*;
import java.util.*;

public class b16_2512 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] budgetList = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        int right = 0;
        for(int i = 0; i < n; i++){
            budgetList[i] = Integer.parseInt(st.nextToken());
            right = Math.max(right, budgetList[i]);
        }

        int maxBudget = Integer.parseInt(br.readLine());

        int left = 0;
        int res = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int budget = 0;

            for(int i = 0; i < n; i++){
                budget += Math.min(budgetList[i], mid);
            }

            if (budget <= maxBudget) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(res);

        br.close();
    }
}
