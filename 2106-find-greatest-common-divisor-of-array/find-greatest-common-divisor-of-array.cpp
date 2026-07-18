class Solution {
public:
    int gcd(int a, int b){
        if(a == 0){
            return b;
        }
        return gcd(b % a, a);
    }
    int findGCD(vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];

        for(int num : nums){
            if(num < min_val) min_val = num;
            if(num > max_val) max_val = num;
        }

        return gcd(min_val, max_val);
    }
};