/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Method 1:
        // if(head == nullptr)
        //     return NULL;
        // set<ListNode*> sln;
        // ListNode* pNode = head;
        // while(pNode->next){
        //     sln.insert(pNode);
        //     pNode = pNode->next;
        //     if(sln.count(pNode))
        //         return pNode;
        // }
        // return NULL;

        // METHOD 2:
        if(head == nullptr )
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr)
                return NULL;
            fast = fast->next->next;
            if(fast == slow)
            {
                ListNode* pre = head;
                while(fast != pre){
                    fast = fast->next;
                    pre = pre->next;
                }
                return pre;
            }
            
        }
        return NULL;
    }
};
// @lc code=end

