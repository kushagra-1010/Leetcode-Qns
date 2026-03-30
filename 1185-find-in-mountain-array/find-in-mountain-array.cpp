/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1;
        int r = mountainArr.length()-2;
        int peak = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            int left = mountainArr.get(m-1);
            int mid = mountainArr.get(m);
            int right = mountainArr.get(m+1);
            if (left < mid && mid < right) {
                l = m+1;
            }
            else if(left > mid && mid > right) {
                r = m-1;
            }
            else {
                peak = m;
                break;
            }
        }

        l = 0;
        r = peak;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (mountainArr.get(mid) > target) {
                r = mid - 1;
            }
            else if (mountainArr.get(mid) < target) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }

        l = peak + 1;
        r = mountainArr.length()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (mountainArr.get(mid) > target) {
                l = mid + 1;
            }
            else if (mountainArr.get(mid) < target) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};