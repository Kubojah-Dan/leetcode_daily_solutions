class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int a = nums[i];
            int sumNum = 0;
            while(a != 0){
                int digit = a % 10;
                sumNum += digit;
                a /= 10;
            }
            if(sumNum == i){
                return i;
            }
        }
        return -1;
    }
};