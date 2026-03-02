class Solution {
public:
    bool isPalindrome(int st,int end,string s){
        while(st<end){
            if(s[st] != s[end]){
                return false;
                break;
            }
            st++;
            end--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int cnt=0;

        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(i,j,s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};