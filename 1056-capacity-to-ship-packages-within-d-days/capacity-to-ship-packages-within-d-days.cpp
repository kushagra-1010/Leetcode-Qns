class Solution {
public:
    bool isValid(vector<int>& weights, int n, int days, int maxLoad) {
        int ships = 1;
        int loads = 0;

        for (int i = 0; i < n; i++) {
            if (weights[i] > maxLoad) return false;

            if (loads + weights[i] <= maxLoad) {
                loads += weights[i];
            } else {
                ships++;
                loads = weights[i];

                if (ships > days) return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int st = 0;
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(weights, n, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};