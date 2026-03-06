class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones=0,zeros=0;
        int MaxOnes=0,MaxZeros=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                zeros=0;
                ones++;
                MaxOnes=max(MaxOnes,ones);
            }
            else if(s[i]=='0')
            {
                ones=0;
                zeros++;
                MaxZeros=max(MaxZeros,zeros);
            }
        }
        if(MaxOnes>MaxZeros)
        {
            return true;
        }
        return false;
    }
};