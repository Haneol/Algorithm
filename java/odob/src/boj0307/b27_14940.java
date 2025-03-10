package boj0307;

import java.io.*;
import java.util.*;

// 14분
public class b27_14940 {
    public static int[][] map;
    public static int[][] visited;
    public static Node[] dir = {new Node(0, 1), new Node(1, 0), new Node(0, -1), new Node(-1, 0)};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new int[n][m];
        Queue<Node> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer mapInput = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(mapInput.nextToken());
                if(map[i][j] == 2) {
                    q.offer(new Node(i, j));
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.isEmpty()) {
            Node cur = q.poll();

            for(int d = 0; d < 4; d++) {
                int dx = cur.x + dir[d].x;
                int dy = cur.y + dir[d].y;

                if(dx < 0 || dy < 0 || dx >= m || dy >= n) continue;

                if(map[dy][dx] == 1 && visited[dy][dx] == 0) {
                    visited[dy][dx] = visited[cur.y][cur.x] + 1;
                    q.offer(new Node(dy, dx));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0) {
                    if(map[i][j] == 0) {
                        sb.append(0);
                    } else if(map[i][j] == 1) {
                        sb.append(-1);
                    }
                } else {
                    sb.append(visited[i][j] - 1);
                }

                if(j < m - 1) sb.append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);

        br.close();
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
