import java.io.*;
import java.util.*;

// 10분
public class b55_1931 {
    static Meeting[] meetings;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        meetings = new Meeting[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            meetings[i] = new Meeting(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(meetings, (a, b) -> {
            int compare = Integer.compare(a.end, b.end);
            if (compare != 0) {
                return compare;
            }
            return Integer.compare(a.start, b.start);
        });

        Meeting currentMeeting = null;
        int count = 0;
        for (Meeting m : meetings) {
            if(currentMeeting == null || currentMeeting.end <= m.start) {
                currentMeeting = m;
                count++;
            }
        }

        System.out.println(count);

        br.close();
    }

    static class Meeting {
        int start;
        int end;

        Meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
