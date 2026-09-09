class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for(long long base = 1000; base <= n; base *= 1000){
            ans += n - base + 1;
        }
        return ans;

    }
};