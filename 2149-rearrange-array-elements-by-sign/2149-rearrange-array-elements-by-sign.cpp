class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg, ans;
        for(int i : nums){
            if(i < 0)neg.push_back(i);
            else pos.push_back(i);
        }
        int i = 0, j = 0, t = 0;
        while(t < n){
            if(t % 2 == 0){
                ans.push_back(pos[i]);
                i++;
                t++;
            }
            else{
                ans.push_back(neg[j]);
                j++;
                t++;
            }
        }
        return ans;
    }
};