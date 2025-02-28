import java.util.*;
import java.io.*;

// 15분
public class b24_2075 {
    public static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n][n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[] pointer = new int[n];
        Arrays.fill(pointer, n-1);
        for(int i = 0; i < n; i++) {
            int maxPos = -1;
            int maxVal = -1000000001;
            for(int j = 0; j < n; j++) {
                if (maxVal < arr[pointer[j]][j]) {
                    maxPos = j;
                    maxVal = arr[pointer[j]][j];
                }
            }
            pointer[maxPos]--;

            if(i == n-1) {
                System.out.println(maxVal);
            }
        }

        br.close();
    }
}
