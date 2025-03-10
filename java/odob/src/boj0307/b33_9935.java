package boj0307;

import java.io.*;
import java.util.*;

// 40분, X
public class b33_9935 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] str = br.readLine().toCharArray();
        char[] bombStr = br.readLine().toCharArray();

        Deque<Character> s = new ArrayDeque<>();
        Deque<Character> s2 = new ArrayDeque<>();

        int i;
        for(char c : str) {
            s.offerFirst(c);

            i = bombStr.length - 1;
            while(!s.isEmpty() && s.peekFirst() == bombStr[i]) {
                s2.offerFirst(s.pollFirst());
                i--;
                // 문자열 폭발
                if(i < 0) {
                    while(!s2.isEmpty()) s2.pollFirst();
                    break;
                }
            }
            // 문자열 복구
            while(!s2.isEmpty()) {
                s.offerFirst(s2.pollFirst());
            }
        }

        StringBuilder sb = new StringBuilder();
        if(!s.isEmpty()) {
            while(!s.isEmpty()) {
                sb.append(s.pollLast());
            }
        } else {
            sb.append("FRULA");
        }

        System.out.println(sb);

        br.close();
    }
}
