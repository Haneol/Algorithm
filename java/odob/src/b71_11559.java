import java.io.*;
import java.util.*;

// 33분
public class b71_11559 {
    static int res;
    static char[][] field = new char[12][6];
    static Node[] dir = {
            new Node(1, 0),
            new Node(-1, 0),
            new Node(0, 1),
            new Node(0, -1),
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int i = 0; i < 12; i++) {
            char[] input = br.readLine().toCharArray();

            for(int j = 0; j < 6; j++) {
                field[i][j] = input[j];
            }
        }

        while(puyo()) {
            res++;
        }

        System.out.println(res);

        br.close();
    }

    static boolean puyo() {
        boolean isExploded = false;
        Queue<Node> q = new LinkedList<>();
        Queue<Node> buffer = new LinkedList<>();
        boolean[][] visited = new boolean[12][6];

        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(visited[i][j] || field[i][j] == '.') continue;

                q.offer(new Node(i, j));
                visited[i][j] = true;

                buffer.clear();
                buffer.offer(new Node(i, j));

                char color = field[i][j];

                while(!q.isEmpty()) {
                    Node cur = q.poll();

                    for(int d = 0; d < 4; d++) {
                        int dx = cur.x + dir[d].x;
                        int dy = cur.y + dir[d].y;

                        if(dx < 0 || dy < 0 || dx >= 6 || dy >= 12) continue;

                        if(!visited[dy][dx] && field[dy][dx] == color) {
                            q.offer(new Node(dy, dx));
                            buffer.offer(new Node(dy, dx));
                            visited[dy][dx] = true;
                        }
                    }
                }

                if(buffer.size() >= 4) {
                    while(!buffer.isEmpty()) {
                        Node cur = buffer.poll();
                        field[cur.y][cur.x] = '.';
                    }

                    isExploded = true;
                }
            }
        }

        List<Character> col = new LinkedList<>();
        for (int i = 0; i < 6; i++) {
            col.clear();
            for (int j = 11; j >= 0; j--) {
                if (field[j][i] != '.') {
                    col.add(field[j][i]);
                    field[j][i] = '.';
                }
            }

            int j = 11;
            for (char ch : col) {
                field[j--][i] = ch;
            }
        }

        return isExploded;
    }

    static class Node {
        int y, x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
