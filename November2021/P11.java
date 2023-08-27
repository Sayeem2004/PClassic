// Solved By Maxwell Zen And Mohammad Khan
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            int n = Integer.parseInt(br.readLine());
            int[][] pvals = new int[n][2];
            int[] nout = new int[n];
            for (int j = 0; j < n; j++) {
                String[] tmp = br.readLine().split(" ");
                pvals[j][0] = Integer.parseInt(tmp[0]);
                pvals[j][1] = Integer.parseInt(tmp[1]);
            }
            for (int j = 0; j < n; j++) {
                nout[j] = Integer.parseInt(br.readLine());
            }
            System.out.println(unbeatable(n, pvals, nout));
        }
        br.close();
    }
    // Do not modify above this line

    public static boolean vis[], beat[];

    public static int unbeatable(int n, int[][] pvals, int[] out) {
        for (int i = 0; i < n; i++) out[i]--;
        vis = new boolean[n];
        beat = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int v1 = pvals[i][0];
            int c1 = pvals[i][1];
            int c = out[i];
            vis[i] = true;
            while (!vis[c]) {
                int v2 = pvals[c][0];
                int c2 = pvals[c][1];
                if (v1 <= v2 && c1 <= c2 && (v1 != v2 || c1 != c2)) {
                    beat[i] = true;
                    break;
                }
                vis[c] = true;
                c = out[c];
            }
            c = i;
            while (vis[c]) {
                vis[c] = false;
                c = out[c];
            }
            if (!beat[i]) ans++;
        }
        return ans;
    }


}
