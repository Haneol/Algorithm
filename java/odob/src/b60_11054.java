import java.io.*;
import java.util.*;

// 33분
public class b60_11054 {
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int max = 0;
        for(int i = 0; i < n; i++){
            max = Math.max(max,
                    lis(0, i, true) + lis(i, n-1, false) - 1);
        }

        System.out.println(max);

        br.close();
    }

    public static int lis(int start, int end, boolean isAsc) {
        int size = 0;
        Integer [] tmp = new Integer[arr.length];

        for (int i = start; i <= end; i++) {
            int pos = isAsc ?
                    Arrays.binarySearch(tmp, 0, size, arr[i]) :
                    Arrays.binarySearch(tmp, 0, size, arr[i], Collections.reverseOrder());

            if (pos < 0) {
                pos = -(pos + 1);
            }

            tmp[pos] = arr[i];
            if(pos == size) size++;
        }

        return size;
    }
}
