package boj0307;

import java.util.*;
import java.io.*;

// 1시간, 메모리초과 X
public class b41_1238 {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        int n = Integer.parseInt(baseInputTokenizer.nextToken());
        int m = Integer.parseInt(baseInputTokenizer.nextToken());
        int x = Integer.parseInt(baseInputTokenizer.nextToken());

        List<ToOtherVillage>[] village = new ArrayList[n+1];
        for(int villageIndex = 1; villageIndex <= n; villageIndex++) {
            village[villageIndex] = new ArrayList<>();
        }

        for (int edgeIndex = 0; edgeIndex < m; edgeIndex++) {
            StringTokenizer edgeInputTokenizer = new StringTokenizer(bufferedReader.readLine());

            int startPoint = Integer.parseInt(edgeInputTokenizer.nextToken());
            int endPoint = Integer.parseInt(edgeInputTokenizer.nextToken());
            int time = Integer.parseInt(edgeInputTokenizer.nextToken());

            village[startPoint].add(new ToOtherVillage(endPoint, time));
        }

        int longestTime = 0;
        PriorityQueue<ToOtherVillage> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.time));
        int[] totalDistance = new int[n+1];

        for(int villageIndex = 1; villageIndex <= n; villageIndex++) {
            Arrays.fill(totalDistance, 1000000);

            pq.offer(new ToOtherVillage(villageIndex, 0));
            totalDistance[villageIndex] = 0;

            while(!pq.isEmpty()) {
                ToOtherVillage currentVillage = pq.poll();

                if(currentVillage.time > totalDistance[currentVillage.village]) continue;

                for(ToOtherVillage nextVillage : village[currentVillage.village]) {
                    int newTime = totalDistance[currentVillage.village] + nextVillage.time;

                    if(totalDistance[nextVillage.village] > newTime) {
                        totalDistance[nextVillage.village] = newTime;
                        pq.offer(new ToOtherVillage(nextVillage.village, newTime));
                    }
                }
            }

            int toTargetVillage = totalDistance[x];
            Arrays.fill(totalDistance, 1000000);
            pq.offer(new ToOtherVillage(x, 0));
            totalDistance[x] = 0;
            while(!pq.isEmpty()) {
                ToOtherVillage currentVillage = pq.poll();

                if(currentVillage.time > totalDistance[currentVillage.village]) continue;

                for(ToOtherVillage nextVillage : village[currentVillage.village]) {
                    int newTime = totalDistance[currentVillage.village] + nextVillage.time;

                    if(totalDistance[nextVillage.village] > newTime) {
                        totalDistance[nextVillage.village] = newTime;
                        pq.offer(new ToOtherVillage(nextVillage.village, newTime));
                    }
                }
            }

            longestTime = Math.max(longestTime, toTargetVillage + totalDistance[villageIndex]);
        }

        System.out.println(longestTime);

        bufferedReader.close();
    }

    static class ToOtherVillage {
        int village;
        int time;

        ToOtherVillage(int village, int time) {
            this.village = village;
            this.time = time;
        }
    }
}
