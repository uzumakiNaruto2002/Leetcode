class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        unordered_map<string, int> m;
        for(int i = 0; i < n - 1; i++){
            string t = "";
            t += s[i];
            t += s[i + 1];
            m[t] = 1;
        }
        for(int i = n - 1; i > 0; i--){
            string t = "";
            t += s[i];
            t += s[i - 1];
            if(m[t] == 1)return true;
        }
        return false;
    }
};