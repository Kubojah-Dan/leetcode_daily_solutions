class Solution {
    static constexpr int MOD = 1e9 + 7;

    struct Node {
        long long sum_x = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0) return;

        long long v = tree[node].lazy;
        tree[node].lazy = 0;

        int mid = start + (end - start) / 2;
        apply(2 * node, start, mid, v);
        apply(2 * node + 1, mid + 1, end, v);
    }

    void apply(int node, int start, int end, long long v) {
        long long len = end - start + 1;
        tree[node].sum_sq = (tree[node].sum_sq + 2 * v % MOD * tree[node].sum_x % MOD + v * v % MOD * len % MOD) % MOD;
        tree[node].sum_x = (tree[node].sum_x + v * len % MOD) % MOD;
        tree[node].lazy = (tree[node].lazy + v) % MOD;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node].sum_x = (tree[2 * node].sum_x + tree[2 * node + 1].sum_x) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(std::vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        std::unordered_map<int, int> last_pos;

        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            
            update(1, 0, n - 1, prev + 1, j, 1);
            
            total_sum = (total_sum + tree[1].sum_sq) % MOD;
            
            last_pos[nums[j]] = j;
        }

        return total_sum;
    }
};