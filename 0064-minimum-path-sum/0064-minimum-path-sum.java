class Solution {
    public int m, n;
    public int[][] dp;

    public int solve(int[][] grid, int i, int j) {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == m - 1) // IF WE ARE ON THE LAST ROW, THEN GO RIGHT
            return dp[i][j] = grid[i][j] + solve(grid, i, j + 1);

        if (j == n - 1) // IF WE ARE ON THE LAST COLUMN, THEN GO DOWN
            return dp[i][j] = grid[i][j] + solve(grid, i + 1, j);

        return dp[i][j] = grid[i][j] + Math.min(solve(grid, i, j + 1), solve(grid, i + 1, j));
    }

    public int minPathSum(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        dp = new int[m][n];

        for (int[] row : dp)
            Arrays.fill(row, -1);

        return solve(grid, 0, 0);
    }
}