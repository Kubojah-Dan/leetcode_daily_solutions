#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int num_queries = queries.size();
        vector<pair<int, int>> sorted_queries(num_queries);
        for(int i = 0; i < num_queries; ++i){
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> ans(num_queries);
        unordered_map<int, int> active_servers;

        int left = 0;
        int right = 0;
        int num_logs = logs.size();

        for(const auto& q : sorted_queries){
            int end_time = q.first;
            int start_time = end_time - x;
            int original_idx = q.second;

            while (right < num_logs && logs[right][1] <= end_time){
                active_servers[logs[right][0]]++;
                right++;
            }

            while (left < num_logs && logs[left][1] < start_time){
                active_servers[logs[left][0]]--;
                if(active_servers[logs[left][0]] == 0){
                    active_servers.erase(logs[left][0]);
                }
                left++;
            }

            ans[original_idx] = n - active_servers.size();
        }
        return ans;
    }
};