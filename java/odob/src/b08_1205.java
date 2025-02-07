import java.io.*;
import java.util.*;

//36분
public class b08_1205 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long newScore = Integer.parseInt(st.nextToken());
        long tmp = 0;
        int p = Integer.parseInt(st.nextToken());
        boolean flag = false;

        if(n == 0) {
            System.out.println(1);
            return;
        }

        StringTokenizer score = new StringTokenizer(br.readLine());

        for(int i = 1; i <= n; i++) {
            long scoreNum = Integer.parseInt(score.nextToken());

            if(scoreNum == newScore && !flag) {
                tmp = i;
                flag = true;
            } else if (scoreNum < newScore) {
                if(flag) {
                    System.out.println(tmp);
                } else {
                    System.out.println(i);
                }
                return;
            }
        }

        if (n < p && flag) {
            System.out.println(tmp);
        } else if (n < p && !flag) {
            System.out.println(n+1);
        } else {
            System.out.println(-1);
        }

        br.close();
    }
}
