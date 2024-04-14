class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.size(), count = 0;
        int x = s[0];
        for(int i = 1; i < n; i++){
            int y = s[i];
            if(x == y || x == y - 32 || x == y + 32){
                continue;
            }
            count++;
            x = y;
        }
        return count;
    }
};