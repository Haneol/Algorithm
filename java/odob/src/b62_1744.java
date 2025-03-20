import java.io.*;
import java.util.*;

// 16분
public class b62_1744 {
    static int[] arr;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        visited = new boolean[n];
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        int res = 0;
        while(true) {
            int maxDiff = -1;
            int inxA = -1, inxB = -1;

            for(int i = 0; i < n - 1; i++){
                if(visited[i]) continue;

                for(int j = i + 1; j < n; j++){
                    if(visited[j]) continue;

                    if(arr[i] * arr[j] > arr[i] + arr[j] && maxDiff < arr[i] * arr[j]) {
                        maxDiff = arr[i] * arr[j];
                        inxA = i;
                        inxB = j;
                    }
                }
            }

            if (maxDiff == -1) {
                break;
            } else {
                res += maxDiff;
                visited[inxA] = true;
                visited[inxB] = true;
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                res += arr[i];
            }
        }

        System.out.println(res);

        br.close();
    }
}
