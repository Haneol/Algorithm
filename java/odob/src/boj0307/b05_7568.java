package boj0307;

import java.io.*;
import java.util.*;

public class b05_7568 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        List<HumanSize> humanSizeList = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            humanSizeList.add(new HumanSize(
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    i
            ));
        }

        int count;
        for(int i = 0; i < n; i++) {
            count = 1;
            for(HumanSize hs : humanSizeList) {
                if(humanSizeList.get(i).height < hs.height && humanSizeList.get(i).weight < hs.weight) {
                    count++;
                }
            }
            System.out.print(count + " ");
        }

        br.close();
    }

    public static class HumanSize {
        int weight;
        int height;

        HumanSize(int weight, int height, int order) {
            this.weight = weight;
            this.height = height;
        }
    }
}
