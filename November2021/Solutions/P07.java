// Solved By Mohammad Khan And Alvin Li
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            String s = br.readLine();
            String t = br.readLine();
            if (matchable(s, t))
                System.out.println("1");
            else
                System.out.println("0");
        }
        br.close();
    }
    // Do not modify above this line

    public static boolean matchable(String initialPattern, String finalPattern) {
        int il = initialPattern.length();
        int fl = finalPattern.length();

        char[] temp = new char[fl];
        for (int i = 0; i < fl; i++) temp[i] = '0';
        for (int i = 0; i < il; i++) temp[i] = initialPattern.charAt(i);

        for (int i = 0; i <= fl-il; i++) {
            boolean ok = true;
            for (int j = 0; j < il; j++) {
                if (initialPattern.charAt(j) == '1' && finalPattern.charAt(i+j) == '0') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int j = 0; j < il; j++) {
                    if (initialPattern.charAt(j) == '1') temp[i+j] = '1';
                }
            }
        }
        // String tmp = new String(temp);
        // System.out.println(tmp);
        for (int i = 0; i < fl; i++) {
            if (temp[i] != finalPattern.charAt(i)) return false;
        }
        return true;
    }
}
