class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = s.size();
        long long count = 0;
        for(auto i: s)if(i == c)count++;
        return ((count)*(count + 1))/2;
    }
};