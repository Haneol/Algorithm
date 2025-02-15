import java.io.*;
import java.util.*;

// 10분
public class b20_21921 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer initInput = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(initInput.nextToken());
        int x = Integer.parseInt(initInput.nextToken());

        StringTokenizer visitCount = new StringTokenizer(br.readLine());
        int[] visitSumList = new int[n+1];
        for (int i = 1; i <= n; i++) {
            visitSumList[i] = visitSumList[i-1] + Integer.parseInt(visitCount.nextToken());
        }

        int maxVisit = 0;
        int maxVisitCount = 0;
        for (int i = x; i <= n; i++) {
            int currentVisitCount = visitSumList[i] - visitSumList[i - x];
            if(maxVisit < currentVisitCount) {
                maxVisit = currentVisitCount;
                maxVisitCount = 1;
            } else if (maxVisit == currentVisitCount) {
                maxVisitCount++;
            }
        }

        if(maxVisit == 0) {
            System.out.println("SAD");
        } else {
            System.out.println(maxVisit);
            System.out.println(maxVisitCount);
        }

        br.close();
    }
}
