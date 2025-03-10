package practice;

import java.util.*;
import java.io.*;

// 13분 /
public class p05_2606 {
    static int totalComputerNumber, computerNetworkSize;
    static boolean[][] computerNetwork;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        totalComputerNumber = Integer.parseInt(bufferedReader.readLine());
        computerNetworkSize = Integer.parseInt(bufferedReader.readLine());

        computerNetwork = new boolean[totalComputerNumber + 1][totalComputerNumber + 1];
        visited = new boolean[totalComputerNumber + 1];
        for(int computerNetworkIndex = 0; computerNetworkIndex < computerNetworkSize; computerNetworkIndex++) {
            StringTokenizer computerNetworkInputTokenizer = new StringTokenizer(bufferedReader.readLine());

            int firstComputer = Integer.parseInt(computerNetworkInputTokenizer.nextToken());
            int secondComputer = Integer.parseInt(computerNetworkInputTokenizer.nextToken());

            computerNetwork[firstComputer][secondComputer] = true;
            computerNetwork[secondComputer][firstComputer] = true;
        }

        // 1. 스택(DFS)으로 풀기
//        stackDfs();

        // 2. 재귀(DFS)로 풀기
        basicDfs();
        // 3. BFS로 풀기

        bufferedReader.close();
    }

    static void stackDfs() {
        ArrayDeque<Integer> s = new ArrayDeque<>();

        s.push(1);
        visited[1] = true;

        int wormCount = 0;
        while(!s.isEmpty()) {
            int currentComputer = s.peek();
            boolean hasNeighborComputer = false;

            for (int networkIndex = 1; networkIndex <= totalComputerNumber; networkIndex++) {
                if(computerNetwork[currentComputer][networkIndex] && !visited[networkIndex]) {
                    visited[networkIndex] = true;
                    s.push(networkIndex);
                    hasNeighborComputer = true;
                    wormCount++;
                }
            }

            if(!hasNeighborComputer) {
                s.pop();
            }
        }

        System.out.println(wormCount);
    }

    static void basicDfs() {
        dfs(1);
        System.out.println(wormCountForDfs - 1);
    }

    static int wormCountForDfs;
    static void dfs(int currentComputer) {
        // 처리
        visited[currentComputer] = true;
        wormCountForDfs++;

        for (int networkIndex = 1; networkIndex <= totalComputerNumber; networkIndex++) {
            if(computerNetwork[currentComputer][networkIndex] && !visited[networkIndex]) {
                dfs(networkIndex);
            }
        }
    }
}
