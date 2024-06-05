class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        map<char,int> m;
        set<char> s;
        for(int i = n - 1; i >= 0; i--){
            if(word[i] >= 97 && word[i] <= 122){
                char c = word[i] - 32;
                if(m[c] == 1 && m[word[i]] != -1){
                    s.insert(word[i]);
                    m[word[i]] = 1;
                }
                else{
                    s.erase(word[i]);
                    m[word[i]] = -1;
                }
            }
            else{
                char c = word[i] + 32;
                if(m[c] == 1){
                    m[c] = -1;
                    s.erase(c);
                }
                else{
                    m[word[i]] = 1;
                }
            }
        }
        // for(auto i: s)cout<<i<<' ';
        return s.size();
    }
};