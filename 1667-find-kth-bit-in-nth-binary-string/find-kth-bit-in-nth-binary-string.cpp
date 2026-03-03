class Solution {
public:
    string build(int n) {
        if(n == 1) return "0";         // base case

        string prev = build(n - 1);    // get Sn-1

        string inverted = prev;
        for(char& c : inverted)
            c = (c == '0') ? '1' : '0';

        reverse(inverted.begin(), inverted.end());

        return prev + "1" + inverted; 
    }

    char findKthBit(int n, int k) {
        string s = build(n);
        return s[k - 1];              
    }
};
