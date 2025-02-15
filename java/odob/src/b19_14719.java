import java.io.*;
import java.util.*;

// 10분
public class b19_14719 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer initInput = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(initInput.nextToken());
        int w = Integer.parseInt(initInput.nextToken());

        boolean[][] world = new boolean[h][w];

        StringTokenizer blockInput = new StringTokenizer(br.readLine());
        for(int i = 0; i < w; i++) {
            int blockHeight = Integer.parseInt(blockInput.nextToken());
            for(int j = 0; j < blockHeight; j++) {
                world[j][i] = true;
            }
        }

        int totalRainCount = 0;
        for(int i = 0; i < h; i++) {
            // 블록과 블록 사이의 개수를 세기
            boolean leftBlock = false;
            int rainCount = 0;
            for(int j = 0; j < w; j++) {
                if(world[i][j]) {
                    if(leftBlock) {
                        totalRainCount += rainCount;
                        rainCount = 0;
                    }
                    leftBlock = true;
                } else if(leftBlock) {
                    rainCount++;
                }
            }
        }

        System.out.println(totalRainCount);

        br.close();
    }
}
