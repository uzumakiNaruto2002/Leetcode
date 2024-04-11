class Solution {
public:
    string capitalizeTitle(string title) {
        string ans = "", s = "";
        int n = title.size();
        for(int i = 0; i < n; i++){
            if(title[i] == ' ' || i == n - 1){
                if(i == n - 1){
                    s += title[i];
                }
                if(s.size() <= 2){
                    for(int j = 0; j < s.size(); j++){
                        char a = s[j] + 32;
                        if(s[j] >= 65 && s[j] <= 90){
                            s[j] = a;
                        }
                    }
                }
                else{
                    for(int j = 0; j < s.size(); j++){
                        char a;
                        if(s[j] >= 97 && s[j] <= 122){
                            if(j == 0){
                                a = s[j] - 32;
                            }
                            else{
                                a = s[j];
                            }
                            s[j] = a;
                        }
                        else if(s[j] >= 65 && s[j] <= 90){
                            if(j > 0){
                                a = s[j] + 32;
                            }
                            else{
                                a = s[j];
                            }
                            s[j] = a;
                        }
                    }
                }
                ans += s;
                ans += ' ';
                s = "";
            }
            else{
                s += title[i];
            }
        }
        ans.pop_back();
        return ans;
    }
};