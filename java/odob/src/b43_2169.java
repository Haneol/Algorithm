import java.util.*;
import java.io.*;

// 45분, 힌트 참고
public class b43_2169 {
    static int[][] board;
    static int[][] dpTable;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer baseInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        int n = Integer.parseInt(baseInputTokenizer.nextToken());
        int m = Integer.parseInt(baseInputTokenizer.nextToken());

        board = new int[n][m];
        dpTable = new int[n][m];
        for (int boardRowIndex = 0; boardRowIndex < n; boardRowIndex++) {
            StringTokenizer boardInputTokenizer = new StringTokenizer(bufferedReader.readLine());
            for (int boardColumnIndex = 0; boardColumnIndex < m; boardColumnIndex++) {
                board[boardRowIndex][boardColumnIndex] = Integer.parseInt(boardInputTokenizer.nextToken());
            }
        }

        // 첫째 줄 초기화
        for (int boardColumnIndex = 0; boardColumnIndex < m; boardColumnIndex++) {
            if (boardColumnIndex == 0) {
                dpTable[0][boardColumnIndex] = board[0][boardColumnIndex];
            } else {
                dpTable[0][boardColumnIndex] = dpTable[0][boardColumnIndex - 1] + board[0][boardColumnIndex];
            }
        }

        // 전체 초기화
        for (int boardRowIndex = 1; boardRowIndex < n; boardRowIndex++) {
            for (int boardColumnIndex = 0; boardColumnIndex < m; boardColumnIndex++) {
                dpTable[boardRowIndex][boardColumnIndex] = Integer.MIN_VALUE;
            }
        }

        int[] tempDpTableRight = new int[m];
        int[] tempDpTableLeft = new int[m];
        for (int boardRowIndex = 1; boardRowIndex < n; boardRowIndex++) {
            Arrays.fill(tempDpTableRight, Integer.MIN_VALUE);
            Arrays.fill(tempDpTableLeft, Integer.MIN_VALUE);

            // 아래 -> 오른쪽
            for (int boardColumnIndex = 0; boardColumnIndex < m; boardColumnIndex++) {
                tempDpTableRight[boardColumnIndex] = dpTable[boardRowIndex - 1][boardColumnIndex] + board[boardRowIndex][boardColumnIndex];
                if(boardColumnIndex != 0) {
                    tempDpTableRight[boardColumnIndex] = Math.max(
                            tempDpTableRight[boardColumnIndex],
                            tempDpTableRight[boardColumnIndex - 1] + board[boardRowIndex][boardColumnIndex]
                    );
                }
            }

            // 아래 -> 왼쪽
            for (int boardColumnIndex = m - 1; boardColumnIndex >= 0; boardColumnIndex--) {
                tempDpTableLeft[boardColumnIndex] = dpTable[boardRowIndex - 1][boardColumnIndex] + board[boardRowIndex][boardColumnIndex];
                if(boardColumnIndex != m - 1) {
                    tempDpTableLeft[boardColumnIndex] = Math.max(
                            tempDpTableLeft[boardColumnIndex],
                            tempDpTableLeft[boardColumnIndex + 1] + board[boardRowIndex][boardColumnIndex]
                    );
                }
            }

            // 값 입력
            for (int boardColumnIndex = 0; boardColumnIndex < m; boardColumnIndex++) {
                dpTable[boardRowIndex][boardColumnIndex] = Math.max(
                        tempDpTableRight[boardColumnIndex],
                        tempDpTableLeft[boardColumnIndex]
                );
            }
        }

        System.out.println(dpTable[n-1][m-1]);

        bufferedReader.close();
    }
}
