class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        string ans = "";
        vector<char> temp;
        for(auto i: s){
            if(i != '?'){
                m[i]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                int mini = INT_MAX;
                char t;
                for(char c = 'a'; c <= 'z'; c++){
                    // cout<<c;
                    if(m[c] < mini){
                        // cout<<m[c]<<' ';
                        t = c;
                        mini = m[c];
                    }
                }
                // cout<<endl;
                temp.push_back(t);
                ans += t;
                m[t]++;
            }
            else{
                ans += s[i];
            }
        }
        sort(temp.begin(), temp.end());
        int j = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                ans[i] = temp[j++];
            }
        }
        return ans;
    }
};