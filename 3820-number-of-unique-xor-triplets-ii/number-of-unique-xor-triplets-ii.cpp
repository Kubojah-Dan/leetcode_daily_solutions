class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(), nums.end());

        unordered_set<int> current_xors = {0};

        for(int step = 0; step < 3; step++){
            unordered_set<int> next_xors;
            for(int val : current_xors){
                for(int x : unique_nums){
                    next_xors.insert(val ^ x);
                }
            }
            current_xors = move(next_xors);
        }
        return current_xors.size();
    }
};