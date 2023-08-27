// Solved By Maxwell Zen, Alvin Li, And Jeremy Ku-Benjet
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PolarTesting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            String amount = br.readLine();
            String[] split = amount.split(" |,");
            System.out.println(testing(Integer.valueOf(split[0]),
                Integer.valueOf(split[1]), Integer.valueOf(split[2])));
        }
        br.close();
    }
    // Do not modify above this line

    public static int testing(int bears, int testtime, int totaltime) {
        int k = totaltime / testtime;
        int ans = 1;
        long cur = k+1;
        while (cur < bears) {
            cur *= (long)k+1;
            ans++;
        }
        return ans;
    }
}
