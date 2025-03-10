package boj0307;

import java.io.*;
import java.util.*;

// 1시간, 힌트 참고
public class b39_1027 {
    static int[] buildings;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        buildings = new int[n + 1];
        StringTokenizer buildingInputTokenizer = new StringTokenizer(br.readLine());
        for (int buildingIndex = 1; buildingIndex <= n; buildingIndex++) {
            buildings[buildingIndex] = Integer.parseInt(buildingInputTokenizer.nextToken());
        }

        int maxValidBuildingCount = 0;
        for (int buildingIndex = 1; buildingIndex <= n; buildingIndex++) {
            // 오른쪽
            int validBuildingCount = 0;
            double previousBuildingSlope;
            if(buildingIndex < n) {
                previousBuildingSlope = calculateSlope(buildingIndex, buildings[buildingIndex], buildingIndex + 1, buildings[buildingIndex + 1]);
                validBuildingCount++;
                for(int targetBuildingIndex = buildingIndex + 2; targetBuildingIndex <= n; targetBuildingIndex++) {
                    double currentBuildingSlope = calculateSlope(buildingIndex, buildings[buildingIndex], targetBuildingIndex, buildings[targetBuildingIndex]);
                    if(previousBuildingSlope < currentBuildingSlope) {
                        validBuildingCount++;
                        previousBuildingSlope = currentBuildingSlope;
                    }
                }
            }

            // 왼쪽
            if(buildingIndex > 1) {
                previousBuildingSlope = calculateSlope(buildingIndex, buildings[buildingIndex], buildingIndex - 1, buildings[buildingIndex - 1]);
                validBuildingCount++;
                for(int targetBuildingIndex = buildingIndex - 2; targetBuildingIndex >= 1; targetBuildingIndex--) {
                    double currentBuildingSlope = calculateSlope(buildingIndex, buildings[buildingIndex], targetBuildingIndex, buildings[targetBuildingIndex]);
                    if(previousBuildingSlope > currentBuildingSlope) {
                        validBuildingCount++;
                        previousBuildingSlope = currentBuildingSlope;
                    }
                }
            }

            maxValidBuildingCount = Math.max(maxValidBuildingCount, validBuildingCount);
        }

        System.out.println(maxValidBuildingCount);

        br.close();
    }

    static double calculateSlope(int sourceBuildingX, int sourceBuildingY, int targetBuildingX, int targetBuildingY) {
        return ((double) targetBuildingY - sourceBuildingY) / (targetBuildingX - sourceBuildingX);
    }
}
