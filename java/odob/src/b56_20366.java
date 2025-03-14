import java.io.*;
import java.util.*;

// 26분
public class b56_20366 {
    static int n;
    static int[] snowball;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        snowball = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            snowball[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(snowball);

        int diff = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int firstSnowman = snowball[i] + snowball[j];

                int left = 0;
                int right = n-1;

                while(left < right) {
                    int secondSnowman = snowball[left] + snowball[right];

                    if(left == i || left == j) {
                        left++;
                    } else if(right == i || right == j) {
                        right--;
                    } else if(firstSnowman == secondSnowman) {
                        System.out.println(0);
                        return;
                    } else if(firstSnowman < secondSnowman) {
                        diff = Math.min(diff, Math.abs(firstSnowman - secondSnowman));
                        right--;
                    } else {
                        diff = Math.min(diff, Math.abs(firstSnowman - secondSnowman));
                        left++;
                    }
                }
            }
        }

        System.out.println(diff);

        br.close();
    }
}
