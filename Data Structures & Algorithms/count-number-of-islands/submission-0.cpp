class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<char>>& grid, int n, int m, int x, int y){
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        for (int i = 0 ; i<4 ; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            dfs(grid,n,m,nx,ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (grid[i][j] == '1'){
                    dfs(grid,n,m,i,j);
                    cout << endl;
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
