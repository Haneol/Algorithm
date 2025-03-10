package practice;

import java.util.*;
import java.io.*;

public class p00_example {

    public static void Main(String[] args) {

    }

    static int knapsack(int[]weight, int[]value, int capacity) {
        int n = weight.length;
        int[][] dp = new int[n+1][capacity+1];

        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= capacity; w++) {
                if(weight[i-1] <= w) {
                    dp[i][w] = Math.max(dp[i-1][w], value[i-1] + dp[i-1][w - weight[i-1]]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }

        return dp[n][capacity];
    }
}
