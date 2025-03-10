package practice;

import java.io.*;

// 18
public class p06_bubbleSort {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int[] list = {1,5,2,4,7,3,6,4,1,4,2,3};
        bubbleSort(list);

        for(int item : list) {
            System.out.print(item + " ");
        }
        System.out.println();

        bufferedReader.close();
    }

    static void bubbleSort(int[] list) {
        int n = list.length;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if (list[j] > list[j+1]) {
                    int tmp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = tmp;
                }
            }
        }
    }
}
