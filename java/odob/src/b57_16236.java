import java.io.*;
import java.util.*;

// 1시간
public class b57_16236 {
    static int[][] fish;
    static boolean[][] visited;
    static Node[] dir = {
            new Node(-1, 0),
            new Node(0, -1),
            new Node(0, 1),
            new Node(1, 0),
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        fish = new int[n][n];
        visited = new boolean[n][n];

        Queue<Node> q = new LinkedList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b) -> {
            int res = Integer.compare(a.y, b.y);
            if (res != 0) return res;
            return Integer.compare(a.x, b.x);
        });

        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                fish[i][j] = Integer.parseInt(st.nextToken());
                if(fish[i][j] == 9){
                    q.offer(new Node(i, j));
                    visited[i][j] = true;
                    fish[i][j] = 0;
                }
            }
        }

        int sharkSize = 2;
        int eatCount = 0;
        int time = 0;
        while (true) {
            boolean flag = false;
            int currentTime = 0;

            // 가장 가까운 물고기 탐색
            while (!q.isEmpty()) {
                int size = q.size();
                currentTime++;

                while  (size-- > 0){
                    Node shark = q.poll();

                    for (int d = 0; d < 4; d++) {
                        int dx = shark.x + dir[d].x;
                        int dy = shark.y + dir[d].y;

                        if (dx < 0 || dy < 0 || dx >= n || dy >= n) {
                            continue;
                        }

                        if (!visited[dy][dx]) {
                            if (fish[dy][dx] == 0 || fish[dy][dx] == sharkSize) {
                                // 이동
                                visited[dy][dx] = true;
                                q.offer(new Node(dy, dx));
                            } else if (fish[dy][dx] < sharkSize) {
                                // 도착
                                flag = true;
                                visited[dy][dx] = true;
                                pq.offer(new Node(dy, dx));
                            }
                        }
                    }
                }
                if (flag) break;
            }

            if(flag) {
                // 물고기 탐색 성공
                Node currentShark = pq.poll();
                fish[currentShark.y][currentShark.x] = 0;

                // 초기화
                q.clear();
                pq.clear();
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        visited[i][j] = false;
                    }
                }

                // 다음 상어 위치
                q.offer(currentShark);
                visited[currentShark.y][currentShark.x] = true;

                // 시간 더하기
                time += currentTime;

                // 상어 크기 키우기
                eatCount++;
                if(eatCount == sharkSize) {
                    eatCount = 0;
                    sharkSize++;
                }
            } else {
                // 물고기 없음
                break;
            }
        }

        System.out.println(time);

        br.close();
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
