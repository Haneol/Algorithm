import java.io.*;
import java.util.*;

// 55분
public class b37_15683 {
    public static int n, m;
    public static int[][] office;
    public static int[][] officeCopy;
    public static List<Node> cctvList = new ArrayList<>();
    public static int[] cctvDirection;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(br.readLine());
        n = Integer.parseInt(baseInputTokenizer.nextToken());
        m = Integer.parseInt(baseInputTokenizer.nextToken());

        office = new int[n][m];
        for (int officeRowIndex = 0; officeRowIndex < n; officeRowIndex++) {
            StringTokenizer officeInputTokenizer = new StringTokenizer(br.readLine());
            for (int officeColumnIndex = 0; officeColumnIndex < m; officeColumnIndex++) {
                office[officeRowIndex][officeColumnIndex] = Integer.parseInt(officeInputTokenizer.nextToken());
                if(office[officeRowIndex][officeColumnIndex] >= 1 && office[officeRowIndex][officeColumnIndex] <= 5) {
                    cctvList.add(new Node(officeRowIndex, officeColumnIndex));
                }
            }
        }

        // 방향 배열, 0 ~ 3
        cctvDirection = new int[cctvList.size()];
        officeCopy = new int[n][m];
        int minCctvUnreachedAreaCount = 100;
        do {
            for(int officeRowIndex = 0; officeRowIndex < n; officeRowIndex++) {
                for(int officeColumnIndex = 0; officeColumnIndex < m; officeColumnIndex++) {
                    officeCopy[officeRowIndex][officeColumnIndex] = office[officeRowIndex][officeColumnIndex];
                }
            }

            for(int cctvIndex = 0; cctvIndex < cctvList.size(); cctvIndex++) {
                Node currentCctv = cctvList.get(cctvIndex);
                if(officeCopy[currentCctv.y][currentCctv.x] == 1) {
                    // 1번 CCTV
                    if (cctvDirection[cctvIndex] == 0) {
                        setCctvArea(currentCctv, 0);
                    } else if (cctvDirection[cctvIndex] == 1) {
                        setCctvArea(currentCctv, 1);
                    } else if (cctvDirection[cctvIndex] == 2) {
                        setCctvArea(currentCctv, 2);
                    } else if (cctvDirection[cctvIndex] == 3) {
                        setCctvArea(currentCctv, 3);
                    }
                } else if(officeCopy[currentCctv.y][currentCctv.x] == 2) {
                    // 2번 CCTV
                    if (cctvDirection[cctvIndex] == 0) {
                        setCctvArea(currentCctv, 1);
                        setCctvArea(currentCctv, 3);
                    } else if (cctvDirection[cctvIndex] == 1) {
                        setCctvArea(currentCctv, 0);
                        setCctvArea(currentCctv, 2);
                    } else if (cctvDirection[cctvIndex] == 2) {
                        setCctvArea(currentCctv, 1);
                        setCctvArea(currentCctv, 3);
                    } else if (cctvDirection[cctvIndex] == 3) {
                        setCctvArea(currentCctv, 0);
                        setCctvArea(currentCctv, 2);
                    }
                } else if(officeCopy[currentCctv.y][currentCctv.x] == 3) {
                    // 3번 CCTV
                    if (cctvDirection[cctvIndex] == 0) {
                        setCctvArea(currentCctv, 0);
                        setCctvArea(currentCctv, 1);
                    } else if (cctvDirection[cctvIndex] == 1) {
                        setCctvArea(currentCctv, 1);
                        setCctvArea(currentCctv, 2);
                    } else if (cctvDirection[cctvIndex] == 2) {
                        setCctvArea(currentCctv, 2);
                        setCctvArea(currentCctv, 3);
                    } else if (cctvDirection[cctvIndex] == 3) {
                        setCctvArea(currentCctv, 3);
                        setCctvArea(currentCctv, 0);
                    }
                } else if(officeCopy[currentCctv.y][currentCctv.x] == 4) {
                    // 4번 CCTV
                    if (cctvDirection[cctvIndex] == 0) {
                        setCctvArea(currentCctv, 0);
                        setCctvArea(currentCctv, 1);
                        setCctvArea(currentCctv, 3);
                    } else if (cctvDirection[cctvIndex] == 1) {
                        setCctvArea(currentCctv, 1);
                        setCctvArea(currentCctv, 0);
                        setCctvArea(currentCctv, 2);
                    } else if (cctvDirection[cctvIndex] == 2) {
                        setCctvArea(currentCctv, 2);
                        setCctvArea(currentCctv, 1);
                        setCctvArea(currentCctv, 3);
                    } else if (cctvDirection[cctvIndex] == 3) {
                        setCctvArea(currentCctv, 3);
                        setCctvArea(currentCctv, 0);
                        setCctvArea(currentCctv, 2);
                    }
                } else if(officeCopy[currentCctv.y][currentCctv.x] == 5) {
                    // 5번 CCTV
                    setCctvArea(currentCctv, 0);
                    setCctvArea(currentCctv, 1);
                    setCctvArea(currentCctv, 2);
                    setCctvArea(currentCctv, 3);
                }
            }

            int cctvUnreachedAreaCount = 0;
            for(int officeRowIndex = 0; officeRowIndex < n; officeRowIndex++) {
                for(int officeColumnIndex = 0; officeColumnIndex < m; officeColumnIndex++) {
                    if(officeCopy[officeRowIndex][officeColumnIndex] == 0) {
                        cctvUnreachedAreaCount++;
                    }
                }
            }

            minCctvUnreachedAreaCount = Math.min(minCctvUnreachedAreaCount, cctvUnreachedAreaCount);
        } while (turnCctvDirection());

        System.out.println(minCctvUnreachedAreaCount);

        br.close();
    }

    public static boolean turnCctvDirection() {
        for(int cctvDirectionIndex = 0; cctvDirectionIndex < cctvDirection.length; cctvDirectionIndex++) {
            if(cctvDirection[cctvDirectionIndex] < 3) {
                cctvDirection[cctvDirectionIndex]++;
                return true;
            } else {
                cctvDirection[cctvDirectionIndex] = 0;
            }
        }

        return false;
    }

    public static void setCctvArea(Node currentCctv, int eachCctvDirection) {
        // 0 : 위
        // 1 : 오른쪽
        // 2 : 아래
        // 3 : 왼쪽
        if (eachCctvDirection == 0) {
            for(int cctvAreaIndex = currentCctv.y; cctvAreaIndex >= 0; cctvAreaIndex--) {
                if(officeCopy[cctvAreaIndex][currentCctv.x] == 6) {
                    break;
                } else if (officeCopy[cctvAreaIndex][currentCctv.x] == 0) {
                    officeCopy[cctvAreaIndex][currentCctv.x] = -1;
                }
            }
        } else if (eachCctvDirection == 1) {
            for(int cctvAreaIndex = currentCctv.x; cctvAreaIndex < m; cctvAreaIndex++) {
                if(officeCopy[currentCctv.y][cctvAreaIndex] == 6) {
                    break;
                } else if (officeCopy[currentCctv.y][cctvAreaIndex] == 0) {
                    officeCopy[currentCctv.y][cctvAreaIndex] = -1;
                }
            }
        } else if (eachCctvDirection == 2) {
            for(int cctvAreaIndex = currentCctv.y; cctvAreaIndex < n; cctvAreaIndex++) {
                if(officeCopy[cctvAreaIndex][currentCctv.x] == 6) {
                    break;
                } else if (officeCopy[cctvAreaIndex][currentCctv.x] == 0) {
                    officeCopy[cctvAreaIndex][currentCctv.x] = -1;
                }
            }
        } else if (eachCctvDirection == 3) {
            for(int cctvAreaIndex = currentCctv.x; cctvAreaIndex >= 0; cctvAreaIndex--) {
                if(officeCopy[currentCctv.y][cctvAreaIndex] == 6) {
                    break;
                } else if (officeCopy[currentCctv.y][cctvAreaIndex] == 0) {
                    officeCopy[currentCctv.y][cctvAreaIndex] = -1;
                }
            }
        }
    }

    public static class Node {
        int y;
        int x;

        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
