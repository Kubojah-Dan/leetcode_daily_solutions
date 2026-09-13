class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>A, B;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(img1[r][c] == 1) A.push_back({r, c});
                if(img2[r][c] == 1) B.push_back({r, c});
            }
        }
        map<pair<int, int>, int> count;
        int max_overlap = 0;

        for(auto& [r1, c1] : A){
            for(auto& [r2, c2] : B){
                pair<int, int> shift = {r2 - r1, c2 - c1};
                count[shift]++;
                max_overlap = max(max_overlap, count[shift]);
            }
        }
        return max_overlap;
    }
};