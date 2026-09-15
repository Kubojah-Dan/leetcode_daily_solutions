class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1;

        for(int center = 0; center < 2 * n - 1; center++){
            int left = center / 2;
            int right = left + (center % 2);

            while(left >= 0 && right < n && s[left] == s[right]){
                int len = right - left + 1;

                if(left > last_end && len >= k){
                    if(len == k || len == k + 1){
                        count++;
                        last_end = right;
                        break;
                    }
                }
                left--;
                right++;
            }
        }
        return count;
    }
};