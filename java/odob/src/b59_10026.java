import java.io.*;
import java.util.*;

// 13분
public class b59_10026 {
    static char[][] board;
    static boolean[][] visited;
    static Node[] dir = {
            new Node(0,1),
            new Node(0,-1),
            new Node(1,0),
            new Node(-1,0),
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        board = new char[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                board[i][j] = input[j];
            }
        }

        Queue<Node> q = new LinkedList<>();
        int[] res = new int[2];
        for(int k = 0; k < 2; k++) {
            // 초기화
            for (boolean[] row : visited) {
                Arrays.fill(row, false);
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j]) continue;

                    q.offer(new Node(i, j));
                    visited[i][j] = true;
                    res[k]++;

                    while(!q.isEmpty()){
                        Node cur = q.poll();

                        for (int d = 0; d < 4; d++) {
                            int dy = cur.y + dir[d].y;
                            int dx = cur.x + dir[d].x;

                            if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;

                            if(!visited[dy][dx]) {
                                if((k == 0 && board[dy][dx] == board[cur.y][cur.x]) ||
                                    k == 1 && equalRG(board[dy][dx], board[cur.y][cur.x])) {
                                    q.offer(new Node(dy, dx));
                                    visited[dy][dx] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        System.out.println(res[0] + " " + res[1]);

        br.close();
    }

    static boolean equalRG(char a, char b) {
        if (a == b) return true;
        if (a == 'R' && (b == 'G')) return true;
        if (a == 'G' && (b == 'R')) return true;

        return false;
    }

    static class Node {
        int y;
        int x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
