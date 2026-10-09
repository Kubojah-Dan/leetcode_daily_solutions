class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open_brackets = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                open_brackets++;
            }else{
            if(i + 1 < n && s[i + 1] == ')'){
                i++;
            }else{
                insertions++;
            }
            if(open_brackets > 0){
                open_brackets--;
            }else{
                insertions++;
            }
            }
        }
        insertions += open_brackets * 2;

        return insertions;
    }
};