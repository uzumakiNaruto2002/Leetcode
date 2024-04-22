class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for(int i = 0; i < n; i++){
            string s = words[i];
            (reverse(s.begin(), s.end()));
            for(int j = i + 1; j < n; j++){
                if(words[i].size() > words[j].size()){
                    continue;
                }
                else{
                    for(int k = 0; k < words[i].size(); k++){
                        if(words[i][k] != words[j][k] || s[k] != words[j][words[j].size() - k - 1]){
                            break;
                        }
                        if(k == words[i].size() - 1)count++;
                    }
                }
            }
        }
        return count;
    }
};