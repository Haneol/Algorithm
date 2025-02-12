import java.io.*;
import java.util.*;

public class b13_20055 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] belt = new int[n * 2];
        int[] robots = new int[n * 2];

        StringTokenizer durabilityInput = new StringTokenizer(br.readLine());
        for (int i = 0; i < n * 2; i++) {
            int durability = Integer.parseInt(durabilityInput.nextToken());
            belt[i] = durability;
        }

        int pushInx = 0;
        int popInx = n-1;

        int res = 0;
        while(true) {
            res++;

            // 1. 벨트 회전
            if(pushInx == 0) pushInx = n*2-1;
            else pushInx--;

            if(popInx == 0) popInx = n*2-1;
            else popInx--;

            robots[popInx] = 0;

            // 2. 로봇 이동
            int i = pushInx;
            for(int j = 0; j < n*2; j++) {
                int nextI = (i == n*2-1) ? 0 : i+1;

                if(robots[i] >= 1 && robots[nextI] == 0 && belt[nextI] > 0) {
                    robots[i]--;
                    robots[nextI]++;
                    belt[nextI]--;
                }

                if(i == 0) i = n*2-1;
                else i--;
            }

            robots[popInx] = 0;

            // 3. 로봇 추가
            if(belt[pushInx] > 0) {
                belt[pushInx]--;
                robots[pushInx]++;
            }

            // 4. 체크
            int zeroDurabilityCount = 0;
            for(int j = 0; j < n * 2; j++) {
                if(belt[j] == 0) {
                    zeroDurabilityCount++;
                    if (zeroDurabilityCount >= k) {
                        System.out.println(res);
                        return;
                    }
                }
            }
        }

    }
}
