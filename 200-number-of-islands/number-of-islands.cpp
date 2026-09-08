class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    q.push({i, j});
                    grid[i][j] = 0;
                    ans++;

                    while(!q.empty()){
                        int sz = q.size();
                        while(sz--){
                            auto [i, j] = q.front();
                            q.pop();

                            int dx[4] = {-1, 0, 1, 0};
                            int dy[4] = {0, -1, 0, 1};

                            for(int k = 0; k < 4; k++){
                                int ni = i + dx[k];
                                int nj = j + dy[k];
                                if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == '1'){
                                    grid[ni][nj] = '0';
                                    q.push({ni, nj});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};