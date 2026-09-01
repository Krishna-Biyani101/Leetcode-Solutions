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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int m = INT_MAX, i = 1;
        int c[2] = {0,0};
        auto prev = head, curr = head->next, nxt = head->next->next;
        auto f = [&]() 
        {
            auto x = prev->val, y = curr->val, z = nxt->val;
            return (x < y && y > z) || (x > y && y < z);
        };
        while(nxt)
        {
            if(f()) 
            {
                if(c[0]) 
                    m = min(m,i - c[c[1]>0]);
                c[c[0]>0] = i;
            }
            prev = curr; 
            curr = nxt;
            nxt = nxt->next; 
            i++;
        }
        if(c[1]) 
            return {m,c[1] - c[0]};
        return {-1,-1};
    }
};