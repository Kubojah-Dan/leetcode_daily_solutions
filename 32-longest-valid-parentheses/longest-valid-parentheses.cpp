class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        vector<int> st = {-1};

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push_back(i);
            }else{
                st.pop_back();

                if(st.empty()){
                    st.push_back(i);
                }else{
                    result = max(result, i - st.back());
                }
            }
        }
        return result;
    }
};