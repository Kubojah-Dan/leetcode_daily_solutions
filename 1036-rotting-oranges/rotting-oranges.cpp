class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }else if(grid[r][c] == 1){
                    freshCount++;
                }
            }
        }
        if(freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty() && freshCount > 0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();

                for(auto& dir : directions){
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return freshCount == 0 ? minutes : -1;
    }
};