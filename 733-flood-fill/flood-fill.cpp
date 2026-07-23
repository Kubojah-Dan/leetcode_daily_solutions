class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor){
        int m = image.size();
        int n = image[0].size();

        if(r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor){
            return;
        }
        image[r][c] = newColor;

        dfs(image, r + 1, c, originalColor, newColor);
        dfs(image, r - 1, c, originalColor, newColor);
        dfs(image, r, c + 1, originalColor, newColor);
        dfs(image, r, c - 1, originalColor, newColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if(originalColor != color){
            dfs(image, sr, sc, originalColor, color);
        }
        return image;
    }
};