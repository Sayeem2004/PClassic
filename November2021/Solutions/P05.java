// Solve By Jeremy Ku-Benjet
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            List<List<Integer>> peacockStats = new ArrayList<>();
            int pos = 0;
            while (true) {
                String peacockStatsLine = br.readLine();
                if (peacockStatsLine == null || peacockStatsLine.equals(""))
                    break;
                peacockStats.add(new ArrayList<Integer>());

                String[] peacockStat = peacockStatsLine.split(" ");
                peacockStats.get(pos).add(Integer.parseInt(peacockStat[0]));
                peacockStats.get(pos).add(Integer.parseInt(peacockStat[1]));
                pos++;
            }

            int[][] peacocks = new int[peacockStats.size()][peacockStats.get(0).size()];

            for (int k = 0; k < peacockStats.size(); k++) {
                for (int j = 0; j < peacockStats.get(0).size(); j++) {
                    peacocks[k][j] = peacockStats.get(k).get(j);
                }
            }

            System.out.println(unbeatable(peacocks));
        }
        br.close();
    }
    // Do not modify above this line

    public static int unbeatable(int[][] peacocks) {
        boolean[] beat = new boolean[peacocks.length];
        for (int i = 0; i < peacocks.length; i++) {
            for (int j = i+1; j < peacocks.length; j++) {
                int v1 = peacocks[i][0];
                int v2 = peacocks[j][0];
                int c1 = peacocks[i][1];
                int c2 = peacocks[j][1];
                if (v1 >= v2 && c1 >= c2 && (v1 != v2 || c1 != c2)) {
                    beat[j] = true;
                }
                if (v1 <= v2 && c1 <= c2 && (v1 != v2 || c1 != c2)) {
                    beat[i] = true;
                }
            }
        }
        int num_beat = 0;
        for (int i = 0; i < beat.length; i++) {
            if (beat[i]) num_beat++;
        }
        return (peacocks.length - num_beat);
    }

}
