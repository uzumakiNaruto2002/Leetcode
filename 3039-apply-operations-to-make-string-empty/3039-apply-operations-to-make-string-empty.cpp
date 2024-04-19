class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size();
        string ans = "";
        int maxi = 0;
        map<char, int> m, m1;
        for(auto i: s)m[i]++;
        for(auto i : m){
            maxi = max(maxi, i.second);
        }
        for(int i = 0; i < n; i++){
            m1[s[i]]++;
            if(m1[s[i]] == maxi){
                ans += s[i];
            }
        }
        return ans;
    }
};