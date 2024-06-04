class Solution {
public:
    string findLatestTime(string s) {
        string ans = "";
        for(int i = 0; i < 5; i++){
            if(s[i] == '?'){
                if(i == 0){
                    if(s[1] == '1' || s[1] == '?' || s[1] == '0'){
                        ans += '1';
                    }
                    else{
                        ans += '0';
                    }
                }
                else if(i == 1){
                    if(s[0] == '1' || s[0] == '?'){
                        ans += '1';
                    }
                    else{
                        ans += '9';
                    }
                }
                else if(i == 3){
                    ans += '5';
                }
                else if(i == 4){
                    ans += '9';
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};