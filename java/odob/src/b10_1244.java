import java.io.*;
import java.util.*;

// 29분, XX
public class b10_1244 {
    public static int n;
    public static int[] switches;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        switches = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            switches[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine());

        for(int i = 0; i < m; i++){
            StringTokenizer controlInfo = new StringTokenizer(br.readLine());

            if(Objects.equals(controlInfo.nextToken(), "1")) {
                toggleM(Integer.parseInt(controlInfo.nextToken()));
            } else {
                toggleW(Integer.parseInt(controlInfo.nextToken()));
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            sb.append(switches[i]);
            if((i + 1) % 20 == 0) {
                sb.append("\n");
            } else {
                sb.append(" ");
            }
        }

        System.out.println(sb);
        br.close();
    }

    public static void toggleM(int x) {
        for(int i = x; i <= n; i+=x) {
            switches[i-1] = toggle(switches[i-1]);
        }
    }

    public static void toggleW(int x) {
        int minDirLen = Math.min(x, n - x + 1);

        for (int i = 0; i < minDirLen; i++) {
            if(switches[x-i-1] == switches[x+i-1]) {
                if(i != 0) {
                    switches[x-i-1] = toggle(switches[x-i-1]);
                }
                switches[x+i-1] = toggle(switches[x+i-1]);
            } else {
                break;
            }
        }
    }

    public static int toggle(int x) {
        return x == 1 ? 0 : 1;
    }
}
