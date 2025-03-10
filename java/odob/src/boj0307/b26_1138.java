package boj0307;

import java.util.*;
import java.io.*;

// 50분, 답안 확인
public class b26_1138 {
    public static int[] peopleList;
    public static int[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        peopleList = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            peopleList[i] = Integer.parseInt(st.nextToken());
        }

        list = new int[n];
        for(int i = 0; i < n; i++) {
            int idx = 0;
            int count = 0;
            while(count != peopleList[i]) {
                if(list[idx] == 0) {
                    count++;
                    idx++;
                } else {
                    idx++;
                }
            }
            while(list[idx] != 0) idx++;
            list[idx] = i+1;
        }

        for(int i = 0; i < n; i++) {
            System.out.print(list[i] + " ");
        }

        br.close();
    }
}
