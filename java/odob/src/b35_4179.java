import java.io.*;
import java.util.*;

// 24분, X (불이 우선임..)
public class b35_4179 {
    public static int r, c;
    public static char[][] maze;
    public static int[][] visited;
    public static Node[] dir = {
            new Node(0, 1, 'X'),
            new Node(0, -1, 'X'),
            new Node(1, 0, 'X'),
            new Node(-1, 0, 'X'),
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(br.readLine());
        r = Integer.parseInt(baseInputTokenizer.nextToken());
        c = Integer.parseInt(baseInputTokenizer.nextToken());

        maze = new char[r][c];
        visited = new int[r][c];
        Queue<Node> q = new LinkedList<>();
        for (int mazeRowIndex = 0; mazeRowIndex < r; mazeRowIndex++) {
            char[] mazeRow = br.readLine().toCharArray();
            for (int mazeColumnIndex = 0; mazeColumnIndex < c; mazeColumnIndex++) {
                maze[mazeRowIndex][mazeColumnIndex] = mazeRow[mazeColumnIndex];
            }
        }

        // 불을 먼저 Queue에 입력
        for (int mazeRowIndex = 0; mazeRowIndex < r; mazeRowIndex++) {
            for (int mazeColumnIndex = 0; mazeColumnIndex < c; mazeColumnIndex++) {
                if(maze[mazeRowIndex][mazeColumnIndex] == 'F') {
                    q.offer(new Node(mazeRowIndex, mazeColumnIndex, 'F'));
                    visited[mazeRowIndex][mazeColumnIndex] = 1;
                }
            }
        }

        // 지훈이를 나중에 입력
        for (int mazeRowIndex = 0; mazeRowIndex < r; mazeRowIndex++) {
            for (int mazeColumnIndex = 0; mazeColumnIndex < c; mazeColumnIndex++) {
                if(maze[mazeRowIndex][mazeColumnIndex] == 'J') {
                    if(isEscape(mazeRowIndex, mazeColumnIndex)) {
                        System.out.println("1");
                        return;
                    }
                    q.offer(new Node(mazeRowIndex, mazeColumnIndex, 'J'));
                    visited[mazeRowIndex][mazeColumnIndex] = 1;
                }
            }
        }

        while(!q.isEmpty()) {
            Node currentNode = q.poll();

            for (int mazeDirection = 0; mazeDirection < dir.length; mazeDirection++) {
                int dy = currentNode.y + dir[mazeDirection].y;
                int dx = currentNode.x + dir[mazeDirection].x;

                if (dx < 0 || dy < 0 || dx >= c || dy >= r) continue;

                if (currentNode.type == 'J' && maze[dy][dx] == '.' && visited[dy][dx] == 0) {
                    // 지훈
                    if(isEscape(dy,dx)) {
                        System.out.println(visited[currentNode.y][currentNode.x] + 1);
                        return;
                    }
                    q.offer(new Node(dy,dx,'J'));
                    visited[dy][dx] = visited[currentNode.y][currentNode.x] + 1;
                    maze[dy][dx] = 'J';
                } else if (currentNode.type == 'F' && (maze[dy][dx] == 'J' || maze[dy][dx] == '.')) {
                    // 불
                    q.offer(new Node(dy,dx,'F'));
                    maze[dy][dx] = 'F';
                }
            }
        }

        System.out.println("IMPOSSIBLE");

        br.close();
    }

    public static boolean isEscape(int y, int x) {
        return y == 0 || x == 0 || y == r - 1 || x == c - 1;
    }

    public static class Node {
        int y;
        int x;
        char type;

        Node(int y, int x, char type) {
            this.y = y;
            this.x = x;
            this.type = type;
        }
    }
}
