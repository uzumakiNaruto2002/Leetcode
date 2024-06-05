class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        set<char> s;
        map<char,int> m;
        for(int i = 0; i < n; i++){
            if(word[i] >= 65 && word[i] <= 90){
                char c = word[i] + 32;
                if(m[c] == 1){
                    s.insert(c);
                }
                m[word[i]] = 1;
            }
            else{
                char c = word[i] - 32;
                if(m[c] == 1){
                    s.insert(word[i]);
                }
                m[word[i]] = 1;
            }
        }
        return s.size();
    }
};