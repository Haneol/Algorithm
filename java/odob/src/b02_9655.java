import java.io.*;

public class b02_9655 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int x = Integer.parseInt(br.readLine());

        if (x % 2 == 0) {
            System.out.println("CY");
        } else {
            System.out.println("SK");
        }

        br.close();
    }
}
