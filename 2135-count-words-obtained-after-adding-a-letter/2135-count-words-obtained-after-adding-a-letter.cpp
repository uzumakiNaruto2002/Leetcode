class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size(), ans = 0;
        unordered_map<string, int> exist;
        vector<string> temp;
        for(int i = 0; i < n; i++){
            unordered_map<char,int> m;
            string s = startWords[i];
            for(int j = 0; j < startWords[i].size(); j++){
                m[startWords[i][j]] = 1;
            }
            for(char j = 'a'; j <= 'z'; j++){
                if(m[j] == 0){
                    s += j;
                    string t = s;
                    sort(t.begin(), t.end());
                    exist[t] = 1;
                    s.pop_back();
                }
            }
        }
        for(int i = 0; i < targetWords.size(); i++){
            string s = targetWords[i];
            sort(s.begin(), s.end());
            if(exist[s] == 1)ans++;
        }
        return ans;
    }
};