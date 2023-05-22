class Solution {
public:
    int n;
    vector<pair<int,int>>island1, island2;
    void fun(int i,int j,int c, vector<vector<int>>& grid){
        if(i == n || j == n || i < 0 || j < 0 || grid[i][j] != 1){
            return ;
        }
        grid[i][j] = c;
        if(c == 2){
            island1.push_back({i, j});
        }
        else{
            island2.push_back({i, j});
        }
        fun(i + 1, j, c, grid);
        fun(i - 1, j, c, grid);
        fun(i, j + 1, c, grid);
        fun(i, j - 1, c, grid);
      
    }
    int shortestBridge(vector<vector<int>>& grid) {
       n = grid.size();
        int c = 2;
        for(int i = 0; i <n; i++){
            for(int j = 0; j < n;j ++){
                if(grid[i][j]){
                    fun(i,j, c, grid);
                    c++;
                }
            }
        }
        int res = INT_MAX;
        for(auto i : island1){
            for(auto j : island2){
                res =min(res, abs(i.first - j.first) + abs(i.second - j.second) - 1);
            }
        }
        return res;
    }
};