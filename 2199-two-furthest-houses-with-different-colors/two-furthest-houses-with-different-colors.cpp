class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=-1;
        for(int i=0;i<colors.size();i++){
            for(int j=colors.size()-1;j>i;j--){
                if(colors[i]!=colors[j]){
                    maxi=max(maxi,j-i);
                }
            }
        }
        return maxi;
    }
};