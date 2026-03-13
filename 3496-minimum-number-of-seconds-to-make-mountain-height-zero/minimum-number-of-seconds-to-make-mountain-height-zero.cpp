class Solution {
public:
    long long maxUnits(long long time, int w) {
        // solve w * k * (k + 1) / 2 <= time
        // k(k+1)/2 <= time / w

        long long t = time / w;

        long long l = 0, r = 1e6; // enough upper bound

        while (l < r) {
            long long m = (l + r + 1) / 2;
            if (m * (m + 1) / 2 <= t) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return l;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e18;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;

            long long total = 0;

            for (int w : workerTimes) {
                total += maxUnits(mid, w);
                if (total >= mountainHeight) break;
            }

            if (total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};