class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;         // doubled string
        int len = t.size();

        int mismatch1 = 0;        // mismatches vs "010101..."
        int mismatch2 = 0;        // mismatches vs "101010..."

        // Build initial window of size n
        for (int i = 0; i < n; i++) {
            char exp1 = (i % 2 == 0) ? '0' : '1';
            char exp2 = (i % 2 == 0) ? '1' : '0';
            if (t[i] != exp1) mismatch1++;
            if (t[i] != exp2) mismatch2++;
        }

        int ans = min(mismatch1, mismatch2);

        // Slide window from position 1 to n-1
        for (int i = n; i < len; i++) {
            // Add new right character (index i)
            char exp1_new = (i % 2 == 0) ? '0' : '1';
            char exp2_new = (i % 2 == 0) ? '1' : '0';
            if (t[i] != exp1_new) mismatch1++;
            if (t[i] != exp2_new) mismatch2++;

            // Remove old left character (index i - n)
            int left = i - n;
            char exp1_old = (left % 2 == 0) ? '0' : '1';
            char exp2_old = (left % 2 == 0) ? '1' : '0';
            if (t[left] != exp1_old) mismatch1--;
            if (t[left] != exp2_old) mismatch2--;

            ans = min(ans, min(mismatch1, mismatch2));
        }

        return ans;
    }
};