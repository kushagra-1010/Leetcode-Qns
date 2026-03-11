class Solution {
public:
    int bitwiseComplement(int n) {
        int res = 0;
        int counter = 0;

        if(n == 0) return 1;

        while(n){
            int rem = n%2;
            res+=pow(2,counter)*(!rem);
            counter++;
            n=n/2;
        }
        return res;
    }
};