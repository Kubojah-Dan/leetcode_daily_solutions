class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        if (n > 0) {
            tree.resize(4 * n, 0);
            build(arr, 1, 0, n - 1);
        }
    }

    int query(int l, int r) {
        if (l > r || n == 0) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
struct Segment {
    char val;
    int L, R;
    int len() const { return R - L + 1; }
};

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> pref1(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref1[i + 1] = pref1[i] + (s[i] == '1' ? 1 : 0);
        }
        vector<Segment> segs;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            segs.push_back({s[i], i, j - 1});
            i = j;
        }

        int m = segs.size();
        vector<int> oneSegIndices; 
        vector<int> oneSegStartPositions;

        for (int i = 0; i < m; ++i) {
            if (segs[i].val == '1') {
                oneSegIndices.push_back(i);
                oneSegStartPositions.push_back(segs[i].L);
            }
        }
        int numOnes = oneSegIndices.size();
        vector<int> interiorGain(numOnes, 0);
        for (int k = 0; k < numOnes; ++k) {
            int i = oneSegIndices[k];
            if (i > 0 && i < m - 1) {
                interiorGain[k] = segs[i - 1].len() + segs[i + 1].len();
            }
        }

        SegmentTree segTree(interiorGain);

        auto calcGain = [&](int segIdx, int l, int r) -> int {
            int left0Len = segs[segIdx].L - max(segs[segIdx - 1].L, l);
            int right0Len = min(segs[segIdx + 1].R, r) - segs[segIdx].R;
            return left0Len + right0Len;
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int totalOnes = pref1[n];

            auto it1 = upper_bound(oneSegStartPositions.begin(), oneSegStartPositions.end(), l);
            int kStart = distance(oneSegStartPositions.begin(), it1);

            int kEnd = -1;
            auto it2 = upper_bound(oneSegStartPositions.begin(), oneSegStartPositions.end(), r);
            int idx = distance(oneSegStartPositions.begin(), it2) - 1;
            
            while (idx >= kStart) {
                int segIdx = oneSegIndices[idx];
                if (segs[segIdx].R < r) {
                    kEnd = idx;
                    break;
                }
                idx--;
            }

            if (kStart > kEnd || kEnd == -1) {
                ans.push_back(totalOnes);
                continue;
            }

            int maxGain = 0;

            maxGain = max(maxGain, calcGain(oneSegIndices[kStart], l, r));
            maxGain = max(maxGain, calcGain(oneSegIndices[kEnd], l, r));

            if (kStart + 1 <= kEnd - 1) {
                maxGain = max(maxGain, segTree.query(kStart + 1, kEnd - 1));
            }

            ans.push_back(totalOnes + maxGain);
        }

        return ans;
    }
};