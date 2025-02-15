import java.io.*;
import java.util.*;


// 43, 시간초과
public class b23_2668 {
    public static int[] arr;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        br.close();
    }

    public static void dfs(int i) {
        if(visited[i]) {

            return;
        }

        dfs(arr[i]);
    }
}
