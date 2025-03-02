import java.io.*;
import java.util.*;

// 1시간
public class b25_16234 {
    public static int[][] nationArr;
    public static boolean[][] visited;
    public static int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInfoInput = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(baseInfoInput.nextToken());
        int l = Integer.parseInt(baseInfoInput.nextToken());
        int r = Integer.parseInt(baseInfoInput.nextToken());

        nationArr = new int[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer nationInfoInput = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                nationArr[i][j] = Integer.parseInt(nationInfoInput.nextToken());
            }
        }

        Queue<Node> q = new LinkedList<>();

        int cnt = 0;
        boolean flag = false;
        while (!flag) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    visited[i][j] = false;
                }
            }

            boolean flag2 = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j])
                        continue;

                    q.offer(new Node(i, j));
                    visited[i][j] = true;

                    int unionSum = nationArr[i][j];
                    int unionCount = 1;
                    ArrayList<Node> unionList = new ArrayList<>();
                    unionList.add(new Node(i, j));
                    while (!q.isEmpty()) {
                        Node cur = q.poll();

                        for (int d = 0; d < 4; d++) {
                            int dx = cur.x + dir[d][0];
                            int dy = cur.y + dir[d][1];

                            if (dx < 0 || dy < 0 || dx >= n || dy >= n)
                                continue;

                            int diff = Math.abs(nationArr[dy][dx] - nationArr[cur.y][cur.x]);

                            if (!visited[dy][dx] && diff >= l && diff <= r) {
                                unionCount++;
                                unionSum += nationArr[dy][dx];
                                unionList.add(new Node(dy, dx));
                                q.offer(new Node(dy, dx));
                                visited[dy][dx] = true;
                            }
                        }

                    }

                    if(unionList.size() > 1 && !flag2) {
                        flag2 = true;
                        cnt++;
                    }

                    for (Node node : unionList) {
                        nationArr[node.y][node.x] = unionSum / unionCount;
                    }
                }
            }
            if(!flag2) {
                flag = true;
            }
        }

        System.out.println(cnt);

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
