import java.io.*;
import java.util.*;

// 13, XX
public class b18_2607 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        String str = br.readLine();
        int[] arr = new int[26];
        for(char c : str.toCharArray()) {
            arr[c - 'A']++;
        }

        int res = 0;
        for(int i = 1; i < n; i++){
            String compareStr = br.readLine();

            int [] compareArr = new int[26];
            for(char c : compareStr.toCharArray()) {
                compareArr[c - 'A']++;
            }

            int tmp = 0;
            for(int j = 0; j < compareArr.length; j++){
                if(arr[j] == compareArr[j]) continue;

                if(Math.abs(arr[j] - compareArr[j]) == 1) {
                    if(tmp == 0 || tmp == 1 && str.length() == compareStr.length()) {
                        tmp++;
                    } else {
                        res++;
                        break;
                    }
                } else {
                    res++;
                    break;
                }
            }
        }

        System.out.println(n - res - 1);

        br.close();
    }
}
