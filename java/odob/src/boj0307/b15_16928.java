package boj0307;

import java.io.*;
import java.util.*;

// 40분, X
public class b15_16928 {
    public static int[] ladderSnake = new int[101];
    public static int[] board = new int[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer initInput = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(initInput.nextToken());
        int m = Integer.parseInt(initInput.nextToken());

        for(int i = 0; i < n + m; i++) {
            StringTokenizer ladderSnakeInput = new StringTokenizer(br.readLine());

            ladderSnake[Integer.parseInt(ladderSnakeInput.nextToken())] = Integer.parseInt(ladderSnakeInput.nextToken());
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        board[1] = 1;
        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int i = 1; i <= 6; i++) {
                int next = cur + i;

                if(next > 100) continue;

                if(ladderSnake[next] != 0) {
                    next = ladderSnake[next];
                }

                if(board[next] == 0) {
                    if(next == 100) {
                        System.out.println(board[cur]);
                    }
                    q.offer(next);
                    board[next] = board[cur] + 1;
                }

            }
        }

        br.close();
    }
}
