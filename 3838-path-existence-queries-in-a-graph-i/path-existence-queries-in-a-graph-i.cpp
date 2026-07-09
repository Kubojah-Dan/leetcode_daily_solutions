class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> arr(n);

        for(int i = 1; i < n; i++){
            arr[i] = arr[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }
        vector<bool> res;

        for(const auto &q : queries){
            res.push_back(arr[q[0]] == arr[q[1]]);
        }
        return res;
    }
};