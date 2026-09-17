class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int[] minLen = new int[n];

        int INF = 1000000;
        java.util.Arrays.fill(minLen, INF);

        int left = 0;
        int currentSum = 0;
        int minResult = INF;
        int bestSoFar = INF;

        for(int right = 0; right < n; right++){
            currentSum += arr[right];
            while(currentSum > target){
                currentSum -= arr[left];
                left++;
            }
            if(currentSum == target){
                int currLen = right - left + 1;

            if(left > 0 && minLen[left - 1] != INF){
                minResult = Math.min(minResult, currLen + minLen[left - 1]);
            }
            bestSoFar = Math.min(bestSoFar, currLen);
        }
        minLen[right] = bestSoFar;
        }
        return minResult >= INF ? -1 : minResult;
    }
}