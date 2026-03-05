class Solution {
public:
    int minOperations(string s) {
        int start_with_zero = 0;
        int start_with_one = 0;

        for(int i=0;i<s.length();i++){
            if(i%2 == 0){
                if(s[i] == '0'){
                    start_with_one ++;
                }else{
                    start_with_zero++;
                }
            }else{
                if(s[i] == '1'){
                    start_with_one ++;
                }else{
                    start_with_zero++;
                }
            }
        }
        return min(start_with_zero,start_with_one);
    }
};