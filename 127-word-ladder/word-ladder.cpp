class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        std::queue<std::string> q;
        q.push(beginWord);

        int steps = 1; 

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                std::string current = q.front();
                q.pop();

                if (current == endWord) {
                    return steps;
                }

                for (int j = 0; j < current.length(); ++j) {
                    char originalChar = current[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;

                        current[j] = c;

                        if (wordSet.count(current)) {
                            q.push(current);
                            wordSet.erase(current); 
                        }
                    }

                    current[j] = originalChar;
                }
            }
            steps++;
        }

        return 0;
    }
};