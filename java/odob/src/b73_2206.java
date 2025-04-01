import java.io.*;
import java.util.*;

// 21분
public class b73_2206 {
    static int[][] board;
    static int[][][] visited;
    static Node[] dir = {
            new Node(1, 0, 0),
            new Node(-1, 0, 0),
            new Node(0, 1, 0),
            new Node(0, -1, 0),
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        board = new int[n][m];
        visited = new int[n][m][2];
        for(int i = 0; i < n; i++) {
            char[] input = br.readLine().toCharArray();
            for(int j = 0; j < m; j++) {
                board[i][j] = input[j] - '0';
            }
        }

        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 0));
        visited[0][0][0] = 1;

        while(!q.isEmpty()) {
            Node cur = q.poll();

            for (int d = 0; d < 4; d++) {
                int dy = cur.y + dir[d].y;
                int dx = cur.x + dir[d].x;

                if (dy < 0 || dx < 0 || dx >= m || dy >= n) continue;

                if (board[dy][dx] == 0 && visited[dy][dx][cur.state] == 0) {
                    q.offer(new Node(dy, dx, cur.state));
                    visited[dy][dx][cur.state] = visited[cur.y][cur.x][cur.state] + 1;
                } else if (cur.state == 0 && board[dy][dx] == 1 && visited[dy][dx][1] == 0) {
                    q.offer(new Node(dy, dx, 1));
                    visited[dy][dx][1] = visited[cur.y][cur.x][0] + 1;
                }
            }
        }

        if (visited[n-1][m-1][0] == 0 && visited[n-1][m-1][1] == 0) {
            System.out.println(-1);
        } else if (visited[n-1][m-1][0] == 0) {
            System.out.println(visited[n-1][m-1][1]);
        } else if (visited[n-1][m-1][1] == 0) {
            System.out.println(visited[n-1][m-1][0]);
        } else {
            System.out.println(Math.min(visited[n-1][m-1][0], visited[n-1][m-1][1]));
        }

        br.close();
    }

    static class Node {
        int y, x, state;

        Node(int y, int x, int state) {
            this.y = y;
            this.x = x;
            this.state = state;
        }
    }
}
