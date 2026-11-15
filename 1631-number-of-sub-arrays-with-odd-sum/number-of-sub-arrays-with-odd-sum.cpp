class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0;
        long long prefixSum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            oddCount += prefixSum % 2;

        }
        oddCount += (n - oddCount) * oddCount;
        return (int) (oddCount % 1000000007);

    }
};