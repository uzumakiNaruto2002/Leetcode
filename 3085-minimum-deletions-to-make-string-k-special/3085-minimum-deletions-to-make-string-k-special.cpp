class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> count, prefix;
        unordered_map<char,int> m;
        for(auto i: word)m[i]++;
        for(auto i: m)count.push_back(i.second);
        sort(count.begin(), count.end());
        prefix.push_back(count[0]);
        int n = count.size();
        for(int i = 1; i < n; i++){
            prefix.push_back(prefix.back() + count[i]);
        }
        int ans = 0;
        set<int> s;
        // for(auto i: count)cout<<i<<' ';
        for(int i = 0; i < n; i++){
            int del = 0, x = count[i] + k;
            auto index = upper_bound(count.begin(), count.end(), x) - count.begin();
            // cout<<index<<' ';
            if(index >= n)return ans;
            if(index > 0){
                del = prefix[n - 1] - prefix[index - 1] - (n - index) * x;
            }
            // cout<<del<<' ';
            if(del <= count[i]){
                ans = ans + del;
                if(s.size() && *s.begin() <= ans){
                    return *s.begin();
                }
                return ans;
            }
            del = del + ans;
            ans = ans + count[i];
            if(s.size() && *s.begin() <= ans){
                return *s.begin();
            }
            // cout<<ans<<' ';
            s.insert(del);
        }
        return ans;
    }
};