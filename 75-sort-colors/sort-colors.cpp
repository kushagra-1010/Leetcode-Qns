class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0;                  // low pointer
        int mid = 0;                 // current pointer
        int end = nums.size() - 1;   // high pointer

        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[st], nums[mid]);
                st++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{  // nums[mid] == 2
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};