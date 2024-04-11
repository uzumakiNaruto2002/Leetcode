class Solution {
public:
    bool checkString(string s) {
        int a = 0, b = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                if(b == 1)return false;
            }
            else{
                b = 1;
            }
        }
        return true;
    }
};