import java.io.*;
import java.util.*;

// 33분
public class b68_15686 {
    static int[][] city;
    static Node[] chickens;
    static Node[] houses;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        city = new int[n][n];
        chickens = new Node[13];
        houses = new Node[n * 2];

        int chickenSize = 0;
        int houseSize = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer cityInput = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                city[i][j] = Integer.parseInt(cityInput.nextToken());
                if (city[i][j] == 2) {
                    chickens[chickenSize++] = new Node(i, j);
                } else if (city[i][j] == 1) {
                    houses[houseSize++] = new Node(i, j);
                }
            }
        }

        int res = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << chickenSize); i++) {
            if (Integer.bitCount(i) != m) continue;

            List<Node> comb = new ArrayList<>();
            for (int j = 0; j < chickenSize; j++) {
                if ((i & (1 << j)) > 0) {
                    comb.add(chickens[j]);
                }
            }

            int minTotalDist = 0;
            for (int j = 0; j < houseSize; j++) {
                int minDist = Integer.MAX_VALUE;
                for (int k = 0; k < m; k++) {
                    minDist = Math.min(minDist, dist(houses[j] ,comb.get(k)));
                }
                minTotalDist += minDist;
            }

            res = Math.min(res, minTotalDist);
        }

        System.out.println(res);

        br.close();
    }

    static int dist(Node a, Node b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

    static class Node {
        int y, x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
