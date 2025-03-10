import java.io.*;
import java.util.*;

public class b49_12015 {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine());
        StringTokenizer numberListInputTokenizer = new StringTokenizer(bufferedReader.readLine());
        int[] numberList = new int[n];
        for(int numberIndex = 0; numberIndex < n; numberIndex++) {
            numberList[numberIndex] = Integer.parseInt(numberListInputTokenizer.nextToken());
        }

        int[] lis = new int[n];
        int size = 0;

        for(int number : numberList) {
            int pos = Arrays.binarySearch(lis, 0, size, number);

            if(pos < 0) {
                pos = -(pos + 1);
            }

            lis[pos] = number;
            if(pos == size) size++;
        }

        System.out.println(size);

        bufferedReader.close();
    }
}
