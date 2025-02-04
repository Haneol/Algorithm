import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class b01_11723 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Set<Integer> set = new HashSet<>();

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < n; i++){
            StringTokenizer commandLine = new StringTokenizer(br.readLine());

            String command = commandLine.nextToken();

            if(command.equals("add")){
                int x = Integer.parseInt(commandLine.nextToken());
                if (checkValidate(x)) {
                    set.add(x);
                }
            } else if(command.equals("remove")){
                int x = Integer.parseInt(commandLine.nextToken());
                if (checkValidate(x)) {
                    set.remove(x);
                }
            } else if(command.equals("check")){
                int x = Integer.parseInt(commandLine.nextToken());
                sb.append(set.contains(x) ? "1\n" : "0\n");
            } else if(command.equals("toggle")){
                int x = Integer.parseInt(commandLine.nextToken());
                if (checkValidate(x)) {
                    if(set.contains(x)){
                        set.remove(x);
                    } else {
                        set.add(x);
                    }
                }
            } else if(command.equals("all")){
                for(int j = 1; j <= 20; j++) {
                    set.add(j);
                }
            } else if(command.equals("empty")){
                set.clear();
            }
        }

        System.out.println(sb);
        br.close();
    }

    private static boolean checkValidate(int num) {
        return num >= 1 && num <= 20;
    }
}
