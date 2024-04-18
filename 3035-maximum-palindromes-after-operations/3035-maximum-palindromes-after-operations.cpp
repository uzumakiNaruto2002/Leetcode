bool comp(string &a, string &b){
    return a.size() < b.size();
}

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        map<char, int> m;
        for(auto i: words){
            for(auto j: i){
                m[j]++;
            }
        }
        sort(words.begin(), words.end(), comp);
        int even = 0, odd = 0;
        int n = words.size(), sum = 0, ans = 0;
        for(auto i: m){
            if(i.second % 2 == 1){
                odd++;
                even = even + i.second - 1;
            }
            else{
                even += i.second;
            }
        }
        for(int i = 0; i < n; i++){
            if(words[i].size() % 2 == 0){
                if(even >= words[i].size()){
                    ans++;
                    even -= words[i].size();
                }
            }
            else{
                if(odd > 0){
                    odd--;
                    if(words[i].size() - 1 == 0){
                        ans++;
                        continue;
                    }
                    if(even >= words[i].size() - 1){
                        ans++;
                        even = even - words[i].size() + 1;
                    }
                }
                else{
                    odd += 2;
                    even -= 2;
                    odd--;
                    if(words[i].size() - 1 == 0){
                        ans++;
                        continue;
                    }
                    if(even >= words[i].size() - 1){
                        ans++;
                        even = even - words[i].size() + 1;
                    }
                }
            }
        }
        return ans;
    }
};