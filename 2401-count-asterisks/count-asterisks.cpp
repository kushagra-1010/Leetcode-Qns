class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool insidePipes = false;

        for (char c : s) {
            if (c == '|') {
                insidePipes = !insidePipes; 
            } else if (c == '*' && !insidePipes) {
                count++;
            }
        }

        return count;
    }
};