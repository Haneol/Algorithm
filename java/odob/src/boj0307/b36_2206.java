package boj0307;

import java.io.*;
import java.util.*;

// 22분, X (시작점 == 도착지 고려)
public class b36_2206 {
    public static int n, m;
    public static int[][] board;
    public static int[][][] visited;
    public static Node[] dir = {
            new Node(1, 0, 0),
            new Node(-1, 0, 0),
            new Node(0, 1, 0),
            new Node(0, -1, 0),
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(br.readLine());
        n = Integer.parseInt(baseInputTokenizer.nextToken());
        m = Integer.parseInt(baseInputTokenizer.nextToken());

        if(n == 1 && m == 1) {
            System.out.println(1);
            return;
        }

        board = new int[n][m];
        visited = new int[n][m][2];
        for (int boardRowIndex = 0; boardRowIndex < n; boardRowIndex++) {
            char[] boardInputArray = br.readLine().toCharArray();
            for (int boardColumnIndex = 0; boardColumnIndex < m; boardColumnIndex++) {
                board[boardRowIndex][boardColumnIndex] = boardInputArray[boardColumnIndex] - '0';
            }
        }

        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 0));
        visited[0][0][0] = 1;
        while(!q.isEmpty()) {
            Node currentNode = q.poll();

            for(int nodeDirectionIndex = 0; nodeDirectionIndex < 4; nodeDirectionIndex++) {
                int dy = currentNode.y + dir[nodeDirectionIndex].y;
                int dx = currentNode.x + dir[nodeDirectionIndex].x;

                if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;

                if(currentNode.blockBreakCount == 0 && visited[dy][dx][0] == 0) {
                    // 아직 한번도 부수지 않음
                    if (dy == n - 1 && dx == m - 1) {
                        System.out.println(visited[currentNode.y][currentNode.x][0] + 1);
                        return;
                    }

                    if(board[dy][dx] == 1) {
                        q.offer(new Node(dy, dx, 1));
                        visited[dy][dx][1] = visited[currentNode.y][currentNode.x][0] + 1;
                    } else {
                        q.offer(new Node(dy, dx, 0));
                        visited[dy][dx][0] = visited[currentNode.y][currentNode.x][0] + 1;
                    }
                } else if(currentNode.blockBreakCount == 1 && visited[dy][dx][1] == 0 && board[dy][dx] == 0) {
                    // 한번 부숨
                    if (dy == n - 1 && dx == m - 1) {
                        System.out.println(visited[currentNode.y][currentNode.x][1] + 1);
                        return;
                    }

                    q.offer(new Node(dy, dx, 1));
                    visited[dy][dx][1] = visited[currentNode.y][currentNode.x][1] + 1;
                }
            }
        }

        System.out.println(-1);

        br.close();
    }

    public static class Node {
        int y;
        int x;
        int blockBreakCount;

        Node(int y, int x, int blockBreakCount) {
            this.y = y;
            this.x = x;
            this.blockBreakCount = blockBreakCount;
        }
    }
}
