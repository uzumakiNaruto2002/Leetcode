class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string, int> m;
        for(int i = 0; i < arr1.size(); i++){
            string s = to_string(arr1[i]);
            string t = "";
            for(int j = 0; j < s.size(); j++){
                t += s[j];
                m[t] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < arr2.size(); i++){
            string s = to_string(arr2[i]);
            string t = "";
            int count = 0;
            for(int j = 0; j < s.size(); j++){
                t += s[j];
                if(m[t] == 1){
                    count = t.size();
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};