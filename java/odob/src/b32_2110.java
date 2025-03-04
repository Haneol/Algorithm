import java.io.*;
import java.util.*;

// 53분, 힌트 참고
public class b32_2110 {
    public static int n, c;
    public static int[] houseArray;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(br.readLine());
        n = Integer.parseInt(baseInputTokenizer.nextToken());
        c = Integer.parseInt(baseInputTokenizer.nextToken());

        houseArray = new int[n];
        for (int houseIndex = 0; houseIndex < n; houseIndex++) {
            houseArray[houseIndex] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(houseArray);

        int startValue = 0;
        int endValue = 1000000000;
        int midValue;
        int maxDistance = 1000000001;
        while (startValue <= endValue) {
            midValue = startValue + (endValue - startValue) / 2;

            if(promising(midValue)) {
                endValue = midValue - 1;
                maxDistance = Math.min(maxDistance, midValue);
            } else {
                startValue = midValue + 1;
            }
        }

        System.out.println(maxDistance);

        br.close();
    }

    public static boolean promising(int midValue) {
        int wifiArea = houseArray[0] + midValue;
        int wifiCount = 1;

        for(int houseIndex = 1; houseIndex < n; houseIndex++) {
            if(wifiCount >= c) return false;

            if(wifiArea < houseArray[houseIndex]) {
                wifiArea = houseArray[houseIndex] + midValue;
                wifiCount++;
            }
        }

        if(wifiCount >= c) return false;
        else return true;
    }
}
