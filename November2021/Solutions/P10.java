// Solved By Maxwell Zen
import java.io.*;
import java.util.*;

public class Main {
    public static long MOD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            String[] inp = br.readLine().split(" ");
            int n = Integer.parseInt(inp[0]);
            int m = Integer.parseInt(inp[1]);
            String s = br.readLine();
            System.out.println(pandaLand(n, m, s));
        }
        br.close();
    }
    // Do not modify above this line

    public static void inc(int i, long x, TreeMap<Integer, Long> tm) {
        if (tm.containsKey(i)) tm.put(i, tm.get(i)+x);
        else tm.put(i, x);
    }
    public static long sum(long i) {
        long ans = ((i%MOD) * ((i+1)%MOD))%MOD;
        if (ans%2==0) ans /= 2;
        else ans = (ans+MOD)/2;
        return ans;
    }
    public static long sum(long i, long j) {
        if (j==0) return 0;
        long ans = sum(j) - sum(i);
        ans %= MOD;
        if (ans<0) ans += MOD;
        return ans;
    }
    public static int pandaLand (int n, int m, String s) {
        int[] r = new int[n], c = new int[m];
        r[0]++; c[0]++;
        int x = 0, y = 0;
        for (int i = 0; i < n+m-2; i++) {
            if (s.charAt(i)=='R') y++;
            else x++;
            r[x]++; c[y]++;
        }
        TreeMap<Integer, Long> rcnt = new TreeMap<Integer, Long>(), ccnt = new TreeMap<Integer, Long>();
        TreeMap<Integer, Long> cnt = new TreeMap<Integer, Long>();
        for (int i = 0; i < n; i++) {
            inc(r[i], 1, rcnt);
        }
        for (int i = 0; i < m; i++) {
            inc(c[i], 1, ccnt);
        }
        Set<Integer> rvals = rcnt.keySet(), cvals = ccnt.keySet();
        // for (Integer i : rvals) {
        //     System.out.println("Rvals " + i + " " + rcnt.get(i));
        // }
        // for (Integer i : cvals) {
        //     System.out.println("Cvals " + i + " " + ccnt.get(i));
        // }
        for (Integer i : rvals) {
            for (Integer j : cvals) {
                int k = i+j;
                inc(k, (long)rcnt.get(i) * (long)ccnt.get(j), cnt);
            }
        }
        x = 0; y = 0;
        inc(r[0]+c[0], -1, cnt);
        inc(r[0]+c[0]-1, 1, cnt);
        for (int i = 0; i < n+m-2; i++) {
            if (s.charAt(i)=='R') y++;
            else x++;
            inc(r[x]+c[y], -1, cnt);
            inc(r[x]+c[y]-1, 1, cnt);
        }
        long k = (long)n*m-1;
        Set<Integer> vals = cnt.keySet();
        long ans = 0;
        for (Integer i : vals) {
            long icnt = cnt.get(i);
            // System.out.println("" + i + " " + icnt + " " + k + " " + sum(k-icnt, k));
            ans += (sum(k-icnt, k) * i)%MOD;
            k -= icnt;
        }
        ans %= MOD;
        if (ans<0) ans += MOD;
        return (int)ans;
    }
}
