class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp_t = t;
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        
        while (temp_t % 2 == 0) { c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { c7++; temp_t /= 7; }
        
        if (temp_t > 1) return "-1";

        int n = num.size();
        auto min_digits_needed = [](int r2, int r3, int r5, int r7) {
            int d9 = r3 / 2;
            r3 %= 2;
            int d8 = r2 / 3;
            r2 %= 3;
            int d7 = r7;
            int d5 = r5;
            
            int d6 = 0, d4 = 0, d3 = r3, d2 = 0;
            if (r2 == 2) {
                if (d3 == 1) {
                    d2 = 1;
                    d6 = 1;
                    d3 = 0;
                } else {
                    d4 = 1;
                }
            } else if (r2 == 1) {
                if (d3 == 1) {
                    d6 = 1;
                    d3 = 0;
                } else {
                    d2 = 1;
                }
            }
            return d9 + d8 + d7 + d6 + d5 + d4 + d3 + d2;
        };

        auto can_fit = [&](int r2, int r3, int r5, int r7, int rem_len) {
            return min_digits_needed(r2, r3, r5, r7) <= rem_len;
        };

        auto fill_suffix = [](int r2, int r3, int r5, int r7, int rem_len) {
            int d9 = r3 / 2; r3 %= 2;
            int d8 = r2 / 3; r2 %= 3;
            int d7 = r7;
            int d5 = r5;
            int d6 = 0, d4 = 0, d3 = r3, d2 = 0;

            if (r2 == 2) {
                if (d3 == 1) {
                    d2 = 1;
                    d6 = 1;
                    d3 = 0;
                } else {
                    d4 = 1;
                }
            } else if (r2 == 1) {
                if (d3 == 1) {
                    d6 = 1;
                    d3 = 0;
                } else {
                    d2 = 1;
                }
            }

            int count_non_ones = d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9;
            int d1 = max(0, rem_len - count_non_ones);

            return string(d1, '1') + string(d2, '2') + string(d3, '3') + 
                   string(d4, '4') + string(d5, '5') + string(d6, '6') + 
                   string(d7, '7') + string(d8, '8') + string(d9, '9');
        };

        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        int first_zero = -1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            int d = num[i] - '0';
            int temp = d;
            int count2 = 0, count3 = 0, count5 = 0, count7 = 0;
            while (temp % 2 == 0) { count2++; temp /= 2; }
            while (temp % 3 == 0) { count3++; temp /= 3; }
            while (temp % 5 == 0) { count5++; temp /= 5; }
            while (temp % 7 == 0) { count7++; temp /= 7; }

            pref2[i + 1] = pref2[i] + count2;
            pref3[i + 1] = pref3[i] + count3;
            pref5[i + 1] = pref5[i] + count5;
            pref7[i + 1] = pref7[i] + count7;
        }
        if (first_zero == -1) {
            int rem2 = max(0, c2 - pref2[n]);
            int rem3 = max(0, c3 - pref3[n]);
            int rem5 = max(0, c5 - pref5[n]);
            int rem7 = max(0, c7 - pref7[n]);
            if (rem2 == 0 && rem3 == 0 && rem5 == 0 && rem7 == 0) {
                return num;
            }
        }

        int max_prefix_len = (first_zero == -1) ? n : first_zero;

        for (int len = max_prefix_len; len >= 0; len--) {
            int start_digit = (len == n) ? 10 : (num[len] - '0' + 1);

            for (int d = start_digit; d <= 9; d++) {
                int temp = d;
                int count2 = 0, count3 = 0, count5 = 0, count7 = 0;
                while (temp % 2 == 0) { count2++; temp /= 2; }
                while (temp % 3 == 0) { count3++; temp /= 3; }
                while (temp % 5 == 0) { count5++; temp /= 5; }
                while (temp % 7 == 0) { count7++; temp /= 7; }

                int req2 = max(0, c2 - pref2[len] - count2);
                int req3 = max(0, c3 - pref3[len] - count3);
                int req5 = max(0, c5 - pref5[len] - count5);
                int req7 = max(0, c7 - pref7[len] - count7);

                int rem_len = n - 1 - len;

                if (can_fit(req2, req3, req5, req7, rem_len)) {
                    string ans = num.substr(0, len);
                    ans += to_string(d);
                    ans += fill_suffix(req2, req3, req5, req7, rem_len);
                    return ans;
                }
            }
        }
        int min_len = min_digits_needed(c2, c3, c5, c7);
        int target_len = max(n + 1, min_len);
        
        return fill_suffix(c2, c3, c5, c7, target_len);
    }
};