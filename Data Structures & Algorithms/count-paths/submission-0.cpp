class Solution {
public:
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    int dp[105][105];
    int uniquePaths(int m, int n, int x, int y){
        if (x == m-1 && y == n-1){
            return 1;
        }
        int &res = dp[x][y];
        if (res != -1) return res;
        res = 0;
        for (int i = 0 ; i<2 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < m && ny < n){
                res += uniquePaths(m,n,nx,ny);
            }
        }
        return res;
    }

    int uniquePaths(int m, int n) {
        for (int i = 0 ; i<=m+1 ; i++){
            for (int j = 0 ; j<=n+1 ; j++){
                dp[i][j] = -1;
            }
        }
        return uniquePaths(m,n,0,0);
    }
};
