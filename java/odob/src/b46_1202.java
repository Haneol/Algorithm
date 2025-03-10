import java.util.*;
import java.io.*;

// 15
public class b46_1202 {
    static Integer[][] jewelryArray;
    static int[] backpackArray;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(bufferedReader.readLine());

        int n = Integer.parseInt(baseInputTokenizer.nextToken());
        int k = Integer.parseInt(baseInputTokenizer.nextToken());

        jewelryArray = new Integer[n][2]; // 0 : 무게, 1 : 가격
        backpackArray = new int[k];

        for (int jewelryIndex = 0; jewelryIndex < n; jewelryIndex++) {
            StringTokenizer jewelryInputTokenizer = new StringTokenizer(bufferedReader.readLine());
            jewelryArray[jewelryIndex][0] = Integer.parseInt(jewelryInputTokenizer.nextToken());
            jewelryArray[jewelryIndex][1] = Integer.parseInt(jewelryInputTokenizer.nextToken());
        }

        for (int backpackIndex = 0; backpackIndex < k; backpackIndex++) {
            backpackArray[backpackIndex] = Integer.parseInt(bufferedReader.readLine());
        }

        // solve
        Arrays.sort(jewelryArray, (jewelryA, jewelryB) -> {
            return Integer.compare(jewelryA[0], jewelryB[0]);
        });
        Arrays.sort(backpackArray);

        PriorityQueue<Integer[]> pq = new PriorityQueue<>((jewelryA, jewelryB) -> {
            return Integer.compare(jewelryB[1], jewelryA[1]);
        });

        int jewelryIndex = 0;
        long jewelryValueSum = 0;
        for (int backpackIndex = 0; backpackIndex < k; backpackIndex++) {
            while(jewelryIndex < n && jewelryArray[jewelryIndex][0] <= backpackArray[backpackIndex]) {
                pq.offer(jewelryArray[jewelryIndex]);
                jewelryIndex++;
            }

            if(!pq.isEmpty()) {
                jewelryValueSum += pq.poll()[1];
            }
        }

        System.out.println(jewelryValueSum);

        bufferedReader.close();
    }
}
