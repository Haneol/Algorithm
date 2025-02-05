import java.io.*;
import java.util.*;

public class b03_10431 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int P = Integer.parseInt(br.readLine());

        int[] studentList = new int[20];

        StringBuilder sb = new StringBuilder();

        while (P-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int T = Integer.parseInt(st.nextToken());
            int count = 0;

            for(int i = 0; i < 20; i++) {
                int currentStudent = Integer.parseInt(st.nextToken());

                for(int j = i; j >= 0; j--) {
                    if(j > 0 && currentStudent < studentList[j - 1]) {
                        studentList[j] = studentList[j - 1];
                        count++;
                    } else {
                        studentList[j] = currentStudent;
                        break;
                    }
                }
            }

            sb.append(T).append(" ").append(count).append("\n");
        }

        System.out.print(sb);

        br.close();
    }
}
