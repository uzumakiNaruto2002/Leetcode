class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m1, m2, m3;
        int n = words.size();
        for(int i = 0; i < n; i++){
            m1[words[i]]++;
            m3[words[i]]++;
        }
        int count = 0, t = 0;
        for(int i = 0; i < n; i++){
            if(m1[words[i]] > 0){
                m2[words[i]] = 1;
                string s = words[i];
                reverse(s.begin(), s.end());
                if(m1[s] > 0 && s[0] != s[1]){
                    m2[s] = 1;
                    count += 4;
                    m1[s]--;
                    m1[words[i]]--;
                }
            }
        }
        for(auto i: m3){
            if(i.first[0] == i.first[1]){
                if(i.second > 1){
                    if(i.second % 2 == 0){
                        count = count + 2 * i.second;
                    }
                    else{
                        count = count + 2 * (i.second - 1);
                    }
                }
                else if(i.second == 1){
                    if(t == 0){
                        t = 1;
                        count += 2;
                    }
                }
            }
        }
        if(t == 0){
            for(auto i : m3){
                if(i.second % 2 == 1 && i.first[0] == i.first[1]){
                    count += 2;
                    break;
                }
            }
        }
        return count;
    }
};