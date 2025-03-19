import java.io.*;
import java.util.*;

// 20분
public class b61_1759 {
    static char[] cypherText;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        cypherText = new char[C];

        StringTokenizer chars = new StringTokenizer(br.readLine());
        for(int i = 0; i < C; i++) {
            cypherText[i] = chars.nextToken().charAt(0);
        }

        Arrays.sort(cypherText);

        List<String> res = new ArrayList<>();
        for (int i = 0; i < (1 << C); i++) {
            StringBuilder text = new StringBuilder();
            int countVowels = 0;
            int countConsonants = 0;
            if (Integer.bitCount(i) == L) {
                for (int j = 0; j < C; j++) {
                    if ((i & (1 << j)) > 0) {
                        text.append(cypherText[j]);
                        if (cypherText[j] == 'a' || cypherText[j] == 'e' || cypherText[j] == 'i'
                        || cypherText[j] == 'o' || cypherText[j] == 'u') {
                            countVowels++;
                        } else {
                            countConsonants++;
                        }
                    }
                }

                if (countVowels >= 1 && countConsonants >= 2) {
                    res.add(text.toString());
                }
            }
        }

        Collections.sort(res);

        StringBuilder sb = new StringBuilder();
        for (String str : res) {
            sb.append(str).append("\n");
        }

        System.out.println(sb);

        br.close();
    }
}
