

string minS(string mini, string s){
    if(mini.size() > s.size())return s;
    else if(mini.size() < s.size())return mini;
    if(mini > s)return s;
    return mini;
}

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans;
        unordered_map<string, unordered_set<string>> m;
        for(int i = 0; i < n; i++){
            string s = arr[i];
            for(int j = 0; j < s.size(); j++){
                string t = "";
                for(int k = j; k < s.size(); k++){
                    t += s[k];
                    m[s].insert(t);
                }
            }
        }
        for(int i = 0; i < n; i++){
            string s = arr[i];
            string mini = "absifeheihfedhfeidhfiehfiehfhnedinfjgvhv";
            for(auto j : m[s]){
                int t = 0;
                for(int k = 0; k < n; k++){
                    if(i == k)continue;
                    if(m[arr[k]].find(j) != m[arr[k]].end()){
                        t = 1;
                        break;
                    }
                }
                if(t == 0){
                    mini = minS(mini, j);
                }
            }
            if(mini == "absifeheihfedhfeidhfiehfiehfhnedinfjgvhv")ans.push_back("");
            else ans.push_back(mini);
        }
        return ans;
    }
};