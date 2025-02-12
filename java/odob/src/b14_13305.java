import java.io.*;
import java.util.*;

// 30분, X
public class b14_13305 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] roads = new int[n-1];
        int[] costs = new int[n];

        StringTokenizer roadsInput = new StringTokenizer(br.readLine());
        for(int i = 0; i < n-1; i++){
            roads[i] = Integer.parseInt(roadsInput.nextToken());
        }

        StringTokenizer costsInput = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            costs[i] = Integer.parseInt(costsInput.nextToken());
        }

        long costSum = 0;
        int minCost = Integer.MAX_VALUE;
        for(int i = 0; i < n-1; i++){
            long nextCost1 = costSum + (long) roads[i] * (long) costs[i];
            long nextCost2 = costSum + (long) roads[i] * minCost;
            if(nextCost1 < nextCost2) {
                costSum = nextCost1;
                minCost = costs[i];
            } else {
                costSum = nextCost2;
            }
        }

        System.out.println(costSum);

        br.close();
    }
}
