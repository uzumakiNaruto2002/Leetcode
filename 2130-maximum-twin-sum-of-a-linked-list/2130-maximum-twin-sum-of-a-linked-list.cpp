/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp != NULL){
            nums.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = nums.size(), i = 0, j = n - 1;
        int ans = 0;
        while(i < j){
            ans = max(ans, nums[i] + nums[j]);
            i++, j--;
        }
        return ans;
    }
};