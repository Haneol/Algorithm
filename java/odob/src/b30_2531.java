import java.io.*;
import java.util.*;

// 43
public class b30_2531 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] belt = new int[n];

        for (int i = 0; i < n; i++) {
            belt[i] = Integer.parseInt(br.readLine());
        }

        Set<Integer> set = new HashSet<>();
        int max = 0;
        for (int i = 0; i < n; i++) {
            set.clear();
            int couponFish = 1;
            for(int j = 0; j < k; j++) {
                set.add(belt[(i+j)%n]);
                if (belt[(i+j)%n] == c) {
                    couponFish = 0;
                }
            }

            max = Math.max(max, set.size() + couponFish);
        }

        System.out.println(max);

        br.close();
    }
}
