class Solution {
private:
    int getDigitSum(int num){
        int sum = 0;
        while (num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        struct Element {
            int digit_sum;
            int value;
            int original_index;
        };

        vector<Element> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = {getDigitSum(nums[i]), nums[i], i}; 
        }

        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b){
            if(a.digit_sum != b.digit_sum){
                return a.digit_sum < b.digit_sum;
            }
            return a.value < b.value;
        });

        vector<bool> visited(n, false);
        int total_swaps = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] || arr[i].original_index == i){
                continue;
            }

            int cycle_size = 0;
            int curr = i;

            while (!visited[curr]){
                visited[curr] = true;
                curr = arr[curr].original_index;
                cycle_size++;
            }

            if(cycle_size > 1){

                total_swaps += (cycle_size - 1);
            }
        }
        return total_swaps;
    }
};