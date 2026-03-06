class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOne = 0, maxZero = 0;
        int currOne = 0, currZero = 0;

        for(char c : s){
            if(c == '1'){
                currOne++;
                currZero = 0;
            } else {
                currZero++;
                currOne = 0;
            }

            maxOne = max(maxOne, currOne);
            maxZero = max(maxZero, currZero);
        }

        return maxOne > maxZero;
    }
};