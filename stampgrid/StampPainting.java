import java.util.*;

public class StampPainting {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            char[][] target = new char[n][n];
            for (int i = 0; i < n; i++) {
                String row = scanner.next();
                target[i] = row.toCharArray();
            }
            int k = scanner.nextInt();
            char[][] stamp = new char[k][k];
            for (int i = 0; i < k; i++) {
                String row = scanner.next();
                stamp[i] = row.toCharArray();
            }
            System.out.println(canPaint(target, stamp) ? "YES" : "NO");
        }
        scanner.close();
    }

    public static boolean canPaint(char[][] target, char[][] stamp) {
        int n = target.length;
        int k = stamp.length;
        boolean[][] painted = new boolean[n][n];
        boolean hasStamped = true;
        while (hasStamped) {
            hasStamped = false;
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (canStamp(target, stamp, i, j, painted)) {
                        stamp(target, stamp, i, j, painted);
                        hasStamped = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (target[i][j] == '*' && !painted[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean canStamp(char[][] target, char[][] stamp, int x, int y, boolean[][] painted) {
        int k = stamp.length;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (stamp[i][j] == '*' && painted[x + i][y + j]) {
                    return false;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (stamp[i][j] == '*' && target[x + i][y + j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    public static void stamp(char[][] target, char[][] stamp, int x, int y, boolean[][] painted) {
        int k = stamp.length;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (stamp[i][j] == '*') {
                    target[x + i][y + j] = '*';
                    painted[x + i][y + j] = true;
                }
            }
        }
    }
}
