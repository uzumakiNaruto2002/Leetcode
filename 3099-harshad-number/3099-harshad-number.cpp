class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        string s = to_string(x);
        for(int i = 0; i < s.size(); i++){
            int t = s[i] - '0';
            sum += t;
        }
        if(x % sum == 0)return sum;
        return -1;
    }
};