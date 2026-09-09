class Solution {
public:

    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<bool>>& ocean, int prevHeight, vector<vector<int>>& heights){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || ocean[r][c] || heights[r][c] < prevHeight){
            return;
        }
        ocean[r][c] = true;

        dfs(r + 1, c, ocean, heights[r][c], heights);
        dfs(r - 1, c, ocean, heights[r][c], heights);
        dfs(r, c + 1, ocean, heights[r][c], heights);
        dfs(r, c - 1, ocean, heights[r][c], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; r++){
            dfs(r, 0, pacific, heights[r][0], heights);
            dfs(r, COLS - 1, atlantic, heights[r][COLS - 1], heights);
        }

        for(int c = 0; c < COLS; c++){
            dfs(0, c, pacific, heights[0][c], heights);
            dfs(ROWS - 1, c, atlantic, heights[ROWS - 1][c], heights);
        }

        vector<vector<int>> result;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};