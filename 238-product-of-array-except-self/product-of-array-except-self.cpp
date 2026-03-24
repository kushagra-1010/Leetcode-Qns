class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        right[n-1] = 1;

        // prefix
        for(int i = 1; i < n; i++){
            left[i] = nums[i-1] * left[i-1];
        }

        // suffix
        for(int i = n-2; i >= 0; i--){
            right[i] = nums[i+1] * right[i+1];
        }

        // answer
        for(int i = 0; i < n; i++){
            nums[i] = left[i] * right[i];
        }

        return nums;
    }
};