import java.io.*;
import java.util.*;

// 50분
public class b80_2146 {
    static int[][] board;
    static int[][] visited;
    static Node[] dir = {
            new Node(1, 0),
            new Node(-1, 0),
            new Node(0, 1),
            new Node(0, -1)
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        visited = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(input.nextToken());
            }
        }

        Queue<Node> q = new LinkedList<>();
        Queue<Node> q2 = new LinkedList<>();
        // 1. 섬 식별
        int idx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 1) continue;

                idx++;
                q.offer(new Node(i, j));
                q2.offer(new Node(i, j));
                board[i][j] = idx;
                while (!q.isEmpty()) {
                    Node cur = q.poll();

                    for (int d = 0; d < 4; d++) {
                        int dy = cur.y + dir[d].y;
                        int dx = cur.x + dir[d].x;

                        if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;

                        if (board[dy][dx] == 1) {
                            board[dy][dx] = idx;
                            q.offer(new Node(dy, dx));
                            q2.offer(new Node(dy, dx));
                        }
                    }
                }
            }
        }

        // 2. 다리 짓기
        int time = 0;
        int res = Integer.MAX_VALUE;
        while (!q2.isEmpty()) {
            int size = q2.size();
            time++;
            while (size-- > 0) {
                Node cur = q2.poll();

                for (int d = 0; d < 4; d++) {
                    int dy = cur.y + dir[d].y;
                    int dx = cur.x + dir[d].x;

                    if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;

                    if (board[dy][dx] == 0) {
                        board[dy][dx] = board[cur.y][cur.x];
                        visited[dy][dx] = visited[cur.y][cur.x] + 1;
                        q2.offer(new Node(dy, dx));
                    } else if (board[dy][dx] != board[cur.y][cur.x]){
                        if(visited[dy][dx] == time) {
                            res = Math.min(res, time * 2 - 1);
                        } else {
                            res = Math.min(res, time * 2 - 2);
                        }
                    }
                }
            }
        }

        System.out.println(res);

        br.close();
    }

    static class Node {
        int y, x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
