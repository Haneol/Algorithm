import java.io.*;
import java.util.*;

// 1시간
public class b76_2457 {
    static Flower[] flowers;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        flowers = new Flower[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            flowers[i] = new Flower(
                    new Date(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())),
                    new Date(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        Arrays.sort(flowers, (a, b) -> {
            int compareMonth = a.start.compareTo(b.start);
            if (compareMonth != 0) {
                return compareMonth;
            }
            return a.end.compareTo(b.end);
        });

        Date pos = new Date(3,1);
        Date tmp = new Date(3,1);
        Date end = new Date(12, 1);
        int cnt = 0;
        int idx = 0;
        while(pos.compareTo(end) < 0) {
            boolean flag = false;

            for (int i = idx; i < n; i++) {
                if (flowers[i].start.compareTo(pos) > 0) {
                    break;
                }

                if (tmp.compareTo(flowers[i].end) < 0) {
                    flag = true;
                    tmp = flowers[i].end;
                    idx = i + 1;
                }
            }

            if (flag) {
                pos = tmp;
                cnt++;
            } else {
                break;
            }
        }

        if (tmp.compareTo(end) < 0) cnt = 0;
        System.out.println(cnt);

        br.close();
    }

    static class Flower {
        Date start, end;

        Flower(Date start, Date end) {
            this.start = start;
            this.end = end;
        }
    }

    static class Date implements Comparable<Date> {
        int month, day;

        public Date(int month, int day) {
            this.month = month;
            this.day = day;
        }

        @Override
        public int compareTo(Date o) {
            if (this.month != o.month) {
                return Integer.compare(this.month, o.month);
            }
            return Integer.compare(this.day, o.day);
        }
    }
}
