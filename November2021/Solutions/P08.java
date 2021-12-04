// Solved By Mohammad Khan
import java.io.*;

public class Main {
    public static int maxPoints(String s, String t) {
        int m = s.length(), n = t.length();
        int[][] DP = new int[m+1][n+1];

        for (int i = 0; i < m+1; i++) {
            DP[i][n] = -(m-i)*2;
        }

        for (int i = 0; i < n+1; i++) {
            DP[m][i] = -(n-i)*2;
        }

        for (int i = m-1; i >= 0; i--) {
            for (int q = n-1; q >= 0; q--) {
                DP[i][q] = Math.max(DP[i+1][q+1] + (s.charAt(i) == t.charAt(q) ? 1 : -1),
                                    Math.max(DP[i+1][q]-2, DP[i][q+1]-2));
            }
        }

        return DP[0][0];
    }

    // Do not modify below this line
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            String s = br.readLine();
            String t = br.readLine();
            System.out.println(maxPoints(s, t));
        }
        br.close();
    }
}
