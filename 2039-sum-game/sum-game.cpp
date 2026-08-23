class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumDiff = 0;
        int qDiff = 0;

        for(int i = 0; i < n; i++){
            if(i < n / 2){
                if(num[i] == '?') qDiff++;
                else sumDiff += num[i] - '0';
            }else{
                if(num[i] == '?') qDiff--;
                else sumDiff -= num[i] - '0';
            }
        }
        return (qDiff % 2 != 0) || (sumDiff * 2 != -9 * qDiff);
    }
};