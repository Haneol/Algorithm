package boj0307;

import java.io.*;
import java.util.*;

// 13분
public class b31_1987 {
    public static int r, c;
    public static char[][] board;
    public static boolean[][] boardVisited;
    public static boolean[] alphabetVisited = new boolean[26];

    public static int maxDepth = 0;

    public static Node[] dir = {
            new Node(0, 1),
            new Node(1, 0),
            new Node(0, -1),
            new Node(-1, 0)
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(br.readLine());
        r = Integer.parseInt(baseInputTokenizer.nextToken());
        c = Integer.parseInt(baseInputTokenizer.nextToken());

        board = new char[r][c];
        boardVisited = new boolean[r][c];
        for(int i = 0; i < r; i++) {
            char[] boardInput = br.readLine().toCharArray();
            for(int j = 0; j < c; j++) {
                board[i][j] = boardInput[j];
            }
        }

        boardVisited[0][0] = true;
        alphabetVisited[board[0][0] - 'A'] = true;
        dfs(new Node(0, 0), 1);

        System.out.println(maxDepth);

        br.close();
    }

    public static void dfs(Node current, int depth) {
        if (depth > maxDepth) {
            maxDepth = depth;
        }

        for(int d = 0; d < 4; d++) {
            int dx = current.x + dir[d].x;
            int dy = current.y + dir[d].y;

            if(dx < 0 || dy < 0 || dx >= c || dy >= r) continue;

            if(!boardVisited[dy][dx] && !alphabetVisited[board[dy][dx] - 'A']) {
                boardVisited[dy][dx] = true;
                alphabetVisited[board[dy][dx] - 'A'] = true;
                dfs(new Node(dy, dx), depth + 1);
                boardVisited[dy][dx] = false;
                alphabetVisited[board[dy][dx] - 'A'] = false;
            }
        }
    }

    public static class Node {
        int x;
        int y;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
