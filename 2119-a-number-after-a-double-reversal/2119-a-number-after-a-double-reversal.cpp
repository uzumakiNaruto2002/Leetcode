class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int k = stoi(s);
        s = to_string(k);
        reverse(s.begin(), s.end());
        k = stoi(s);
        return k == num;
    }
};