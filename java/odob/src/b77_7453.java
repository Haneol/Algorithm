import java.io.*;
import java.util.*;

// 45분
public class b77_7453 {
    static int[][] array;
    static int[] arr1, arr2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        array = new int[4][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            array[0][i] = Integer.parseInt(st.nextToken());
            array[1][i] = Integer.parseInt(st.nextToken());
            array[2][i] = Integer.parseInt(st.nextToken());
            array[3][i] = Integer.parseInt(st.nextToken());
        }

        arr1 = new int[n * n];
        arr2 = new int[n * n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr1[i * n + j] = array[0][i] + array[1][j];
                arr2[i * n + j] = array[2][i] + array[3][j];
            }
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        int start = 0;
        int end = n * n - 1;
        long cnt = 0;
        while(start < n * n && end >= 0) {
            if(arr1[start] + arr2[end] == 0) {
                long cnt1 = 1;
                long cnt2 = 1;
                while(start < n * n - 1 && arr1[start] == arr1[start+1]) {
                    cnt1++;
                    start++;
                }
                while(end > 0 && arr2[end] == arr2[end-1]) {
                    cnt2++;
                    end--;
                }
                cnt += cnt1 * cnt2;
                start++;
                end--;
            } else if (arr1[start] + arr2[end] > 0) {
                end--;
            } else {
                start++;
            }
        }

        System.out.println(cnt);

        br.close();
    }
}
