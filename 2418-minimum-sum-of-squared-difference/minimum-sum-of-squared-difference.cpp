class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diffCount(100001, 0);
        long long totalDiff = 0;

        for(int i = 0; i < n; i++){
            int diff = abs(nums1[i] - nums2[i]);
            diffCount[diff]++;
            totalDiff += diff;
        }

        if(k >= totalDiff){
            return 0;
        }

        for(int d = 100000; d > 0 && k > 0; d--){
            if(diffCount[d] > 0){
                long long reduceCount = min(diffCount[d], k);

                diffCount[d] -= reduceCount;
                diffCount[d - 1] += reduceCount;
                k -= reduceCount;
            }
        }

        long long ans = 0;
        for(long long d = 1; d <= 100000; d++){
            if(diffCount[d] > 0){
                ans += diffCount[d] * d * d;
            }
        }
        return ans;
    }
};