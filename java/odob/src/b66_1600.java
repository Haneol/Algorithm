import java.io.*;
import java.util.*;

// 36분
public class b66_1600 {
    static int[][] board;
    static int[][][] visited;
    static Node[] dir = {
            // monkey
            new Node(1, 0, 0),
            new Node(-1, 0, 0),
            new Node(0, 1, 0),
            new Node(0, -1, 0),

            // horse
            new Node(-2, -1, 0),
            new Node(-2, 1, 0),
            new Node(1, 2, 0),
            new Node(-1, 2, 0),
            new Node(2, -1, 0),
            new Node(2, 1, 0),
            new Node(1, -2, 0),
            new Node(-1, -2, 0),
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int k = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        board = new int[h][w];
        visited = new int[h][w][k+1];

        for (int i = 0; i < h; i++) {
            StringTokenizer boardInput = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
                board[i][j] = Integer.parseInt(boardInput.nextToken());
            }
        }

        for (int[][] x : visited) {
            for (int[] row : x) {
                Arrays.fill(row, Integer.MAX_VALUE);
            }
        }
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 0));
        visited[0][0][0] = 1;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            for (int d = 0; d < 4; d++) {
                int dx = cur.x + dir[d].x;
                int dy = cur.y + dir[d].y;

                if (dx < 0 || dy < 0 || dx >= w || dy >= h) continue;

                if (visited[dy][dx][cur.horseMove] == Integer.MAX_VALUE && board[dy][dx] == 0) {
                    visited[dy][dx][cur.horseMove] = visited[cur.y][cur.x][cur.horseMove] + 1;
                    q.offer(new Node(dy, dx, cur.horseMove));
                }
            }

            if (cur.horseMove >= k) continue;

            for (int d = 4; d < 12; d++) {
                int dx = cur.x + dir[d].x;
                int dy = cur.y + dir[d].y;

                if (dx < 0 || dy < 0 || dx >= w || dy >= h) continue;

                if (visited[dy][dx][cur.horseMove + 1] == Integer.MAX_VALUE && board[dy][dx] == 0) {
                    visited[dy][dx][cur.horseMove + 1] = visited[cur.y][cur.x][cur.horseMove] + 1;
                    q.offer(new Node(dy, dx, cur.horseMove + 1));
                }
            }
        }

        int minAction = Integer.MAX_VALUE;
        for (int i = 0; i <= k; i++) {
            minAction = Math.min(minAction, visited[h - 1][w - 1][i]);
        }

        System.out.println(minAction == Integer.MAX_VALUE ? -1 : minAction - 1);

        br.close();
    }

    static class Node {
        int x, y, horseMove;

        Node(int y, int x, int horseMove) {
            this.y = y;
            this.x = x;
            this.horseMove = horseMove;
        }
    }
}
