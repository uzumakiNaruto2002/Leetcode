class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> ans;
        map<long long, long long> m1,m2;
        priority_queue<long long> pq;
        m1[nums[0]] = freq[0];
        pq.push(freq[0]);
        ans.push_back(freq[0]);
        m2[freq[0]] = 1;
        for(int i = 1; i < n; i++){
            m2[m1[nums[i]]]--;
            if(m2[m1[nums[i]]] == 0){
                m2.erase(m1[nums[i]]);
            }
            m1[nums[i]] = m1[nums[i]] + (long long)freq[i];
            m2[m1[nums[i]]]++;
            // for(auto i : m2)cout<<i.first<<' ';
            // cout<<endl;
            ans.push_back(prev(m2.end()) -> first);
        }
        return ans;
    }
};