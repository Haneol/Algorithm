import java.io.*;
import java.util.*;

// 40분
public class b54_16987 {
    static int n;
    static Egg[] eggs;
    static int maxBrokenEggs;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        eggs = new Egg[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            eggs[i] = new Egg(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        bt(0, eggs);

        System.out.println(maxBrokenEggs);

        br.close();
    }

    static void bt(int depth, Egg[] currentEggs) {
        if (depth >= n) {
            int currentBrokenEggs = 0;
            for (Egg egg : currentEggs) {
                if (egg.durability <= 0) {
                    currentBrokenEggs++;
                }
            }
            maxBrokenEggs = Math.max(maxBrokenEggs, currentBrokenEggs);

            return;
        }

        if (currentEggs[depth].durability <= 0) {
            bt(depth + 1, currentEggs);
            return;
        }

        boolean flag = false;
        for (int i = 0; i < n; i++) { // 이번에 부술 놈, depth는 선택한 놈
            if(currentEggs[i].durability <= 0 || i == depth) continue;
            flag = true;

            Egg currentEggA = currentEggs[depth];
            Egg currentEggB = currentEggs[i];

            currentEggs[depth] = new Egg(
                    currentEggs[depth].durability - currentEggs[i].weight,
                    currentEggs[depth].weight);
            currentEggs[i] = new Egg(
                    currentEggs[i].durability - currentEggs[depth].weight,
                    currentEggs[i].weight);
            bt(depth + 1, currentEggs);
            currentEggs[depth] = currentEggA;
            currentEggs[i] = currentEggB;
        }

        if(!flag) {
            bt(depth + 1, currentEggs);
        }
    }

    static class Egg {
        int durability;
        int weight;

        Egg(int durability, int weight) {
            this.durability = durability;
            this.weight = weight;
        }
    }
}
