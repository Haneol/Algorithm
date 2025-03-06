package pracPermNComb;

import java.io.*;
import java.util.*;

//36
public class p02_9742 {
    static String resultString;
    static int countResultArray;
    static char[] resultArray;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String permutationInputString;
        while((permutationInputString = bufferedReader.readLine()) != null && !permutationInputString.isEmpty()) {
            StringTokenizer permutationInputToken = new StringTokenizer(permutationInputString);

            String testString = permutationInputToken.nextToken();
            int nthPermutationString = Integer.parseInt(permutationInputToken.nextToken());

            resultArray = new char[testString.length()];
            visited = new boolean[testString.length()];
            countResultArray = 0;
            permutation(testString, 0, nthPermutationString);

            if (countResultArray < nthPermutationString) {
                System.out.println(permutationInputString + " = No permutation");
            } else {
                System.out.println(permutationInputString + " = " + resultString);
            }
        }

        bufferedReader.close();
    }

    static void permutation(String inputString, int depth, int findLocation) {
        if(depth == inputString.length()) {
            countResultArray++;
            if(findLocation == countResultArray) {
                resultString = String.valueOf(resultArray);
            }
            return;
        }

        for (int inputStringIndex = 0; inputStringIndex < inputString.length(); inputStringIndex++) {
            if(!visited[inputStringIndex] && countResultArray <= findLocation) {
                visited[inputStringIndex] = true;
                resultArray[depth] = inputString.charAt(inputStringIndex);
                permutation(inputString,depth + 1, findLocation);
                visited[inputStringIndex] = false;
            }
        }
    }
}
