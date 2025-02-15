import java.io.*;
import java.util.*;


// 13분
public class b20_2467 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer initInput = new StringTokenizer(br.readLine());
        int[] liquid = new int[n];
        for (int i = 0; i < n; i++) {
            liquid[i] = Integer.parseInt(initInput.nextToken());
        }

        int left = 0;
        int right = n - 1;

        int leftWhenMin = 0;
        int rightWhenMin = n - 1;
        int sumMin = 2000000000;
        while(left < right) {
            int sum = liquid[left] + liquid[right];

            if(Math.abs(sum) < Math.abs(sumMin)) {
                sumMin = sum;
                leftWhenMin = left;
                rightWhenMin = right;
            }

            if(sum > 0) {
                right--;
            } else if(sum < 0) {
                left++;
            } else {
                break;
            }
        }

        System.out.println(liquid[leftWhenMin] + " " + liquid[rightWhenMin]);

        br.close();
    }
}
