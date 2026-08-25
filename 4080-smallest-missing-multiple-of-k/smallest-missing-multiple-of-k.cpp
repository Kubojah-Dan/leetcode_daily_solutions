class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int multiple = k;
        int n = nums.size();

        while(st.count(multiple)){
            multiple += k;
        }
        return multiple;
    }
};