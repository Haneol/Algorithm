package boj0307;

import java.io.*;

public class b06_4659 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();

        while(true) {
            String password = br.readLine();

            if(password.equals("end")) break;

            boolean hasVowel = false;
            int countContinuousLetter = 0;
            char previousChar = '-';
            boolean flag = false;

            for(char c : password.toCharArray()) {
                boolean isCurVowel = false;
                boolean isPrevVowel = false;
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    hasVowel = true;
                    isCurVowel = true;
                }
                if(previousChar == 'a' || previousChar == 'e' || previousChar == 'i' || previousChar == 'o' || previousChar == 'u') {
                    isPrevVowel = true;
                }

                if(c == 'e' && previousChar == 'e' || c == 'o' && previousChar == 'o') {
                    countContinuousLetter++;
                } else if (c == previousChar) {
                    flag = true;
                    break;
                } else if(isCurVowel == isPrevVowel && previousChar != '-') {
                    countContinuousLetter++;
                } else {
                    countContinuousLetter = 0;
                }

                if(countContinuousLetter >= 2) {
                    flag = true;
                    break;
                }

                previousChar = c;
            }

            if(flag) {
                sb.append("<").append(password).append("> is not acceptable.\n");
            } else {
                if(!hasVowel) {
                    sb.append("<").append(password).append("> is not acceptable.\n");
                } else {
                    sb.append("<").append(password).append("> is acceptable.\n");
                }
            }
        }

        System.out.println(sb);

        br.close();
    }
}