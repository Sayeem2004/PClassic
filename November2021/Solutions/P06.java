// Solved By Alvin Li
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            List<List<Integer>> arr = new ArrayList<>();
            while (true) {
                String s = br.readLine();
                if (s.equals("")) {
                    break;
                }
                arr.add(Stream.of(s.trim().split(" ")).map(Integer::parseInt).collect(toList()));
            }
            int[][] grid = new int[arr.size()][arr.get(0).size()];
            for (int k = 0; k < arr.size(); k++) {
                for (int j = 0; j < arr.get(0).size(); j++) {
                    grid[k][j] = arr.get(k).get(j);
                }
            }
            if (magicSquare(grid)) {
                System.out.println("true");
            } else {
                System.out.println("false");
            }
        }
        br.close();
    }
    // Do not modify above this line

    public static boolean ism(int[][] grid, int i, int j){ //i,j is top left corner
        int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        for(int ii=0; ii<3; ii++) {
            if (grid[i+ii][j] + grid[i+ii][j+1] + grid[i+ii][j+2] != s) return false;
        }
        for(int jj=0; jj<3; jj++) {
            if (grid[i][j+jj] + grid[i+1][j+jj] + grid[i+2][j+jj] != s) return false;
        }
        if(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s || grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s) return false;
        return true;
    }

    public static boolean magicSquare(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                //System.out.println(i + " " + j);
                if (ism(grid, i, j)) return true;
            }
        }
        return false;
    }
}
