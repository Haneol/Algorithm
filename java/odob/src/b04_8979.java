import java.io.*;
import java.util.*;

public class b04_8979 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputInfo = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(inputInfo.nextToken());
        int k = Integer.parseInt(inputInfo.nextToken());

        List<NationInfo> olympicNations = new ArrayList<>();

        for(int i = 0; i < n; i++){
            StringTokenizer nationScoreInfo = new StringTokenizer(br.readLine());

            int nationNumber = Integer.parseInt(nationScoreInfo.nextToken());
            int goldMedalCounts = Integer.parseInt(nationScoreInfo.nextToken());
            int silverMedalCounts = Integer.parseInt(nationScoreInfo.nextToken());
            int bronzeMedalCounts = Integer.parseInt(nationScoreInfo.nextToken());

            olympicNations.add(new NationInfo(nationNumber, goldMedalCounts, silverMedalCounts, bronzeMedalCounts));
        }

        olympicNations.sort((nation1, nation2) -> {
            int comparison1 = Integer.compare(nation2.goldMedalCounts, nation1.goldMedalCounts);
            if(comparison1 != 0) return comparison1;
            int comparison2 = Integer.compare(nation2.silverMedalCounts, nation1.silverMedalCounts);
            if(comparison2 != 0) return comparison2;
            int comparison3 = Integer.compare(nation2.bronzeMedalCounts, nation1.bronzeMedalCounts);
            if(comparison3 != 0) return comparison3;

            return Integer.compare(nation1.nationNumber, nation2.nationNumber);
        });

        int result = 0;
        int tmp = 0;
        NationInfo previousNationInfo = null;
        for(NationInfo nationInfo : olympicNations){
            if(previousNationInfo != null &&
                previousNationInfo.goldMedalCounts == nationInfo.goldMedalCounts &&
                previousNationInfo.silverMedalCounts == nationInfo.silverMedalCounts &&
                previousNationInfo.bronzeMedalCounts == nationInfo.bronzeMedalCounts
            ) {
                tmp++;
            } else {
                result = result + 1 + tmp;
                tmp = 0;
            }

            if(nationInfo.nationNumber == k) {
                System.out.println(result);
            }

            previousNationInfo = nationInfo;
        }

        br.close();
    }

    public static class NationInfo {
        int nationNumber;
        int goldMedalCounts;
        int silverMedalCounts;
        int bronzeMedalCounts;

        NationInfo(int nationNumber, int goldMedalCounts, int silverMedalCounts, int bronzeMedalCounts) {
            this.nationNumber = nationNumber;
            this.goldMedalCounts = goldMedalCounts;
            this.silverMedalCounts = silverMedalCounts;
            this.bronzeMedalCounts = bronzeMedalCounts;
        }
    }
}
