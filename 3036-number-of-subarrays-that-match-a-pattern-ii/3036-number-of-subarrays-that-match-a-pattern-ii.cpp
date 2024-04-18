
int rabin_karp(vector<int> &temp, vector<int> pattern){
    int n = temp.size(), m = pattern.size();
    long long mod = 1e9 + 7, hashTemp = 0, hashPattern = 0, prime = 37, power = 1;
    for(int i = 0; i < m; i++){
        hashPattern = (prime * hashPattern + (long long)(pattern[i] + 1)) % mod;
        power = (power * prime) % mod;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        hashTemp = (prime * hashTemp + (long long)(temp[i] + 1)) % mod;
        if(i >= m){
            hashTemp = (hashTemp - power * (temp[i - m] + 1) % mod + mod) % mod;
        }
        if(i >= m - 1 && hashTemp == hashPattern)ans++;
    }
    return ans;
}

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size(), n = nums.size();
        int ans = 0;
        vector<int> temp;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] < nums[i + 1]){
                temp.push_back(1);
            }
            else if(nums[i] == nums[i + 1]){
                temp.push_back(0);
            }
            else{
                temp.push_back(-1);
            }
        }
        return rabin_karp(temp, pattern);                                    
    }
};