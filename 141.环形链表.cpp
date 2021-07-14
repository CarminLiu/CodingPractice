/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        // METHOD 1: or unordered_set
        // set<ListNode*> sln;
        // ListNode* pNode = head;
        // while(pNode!=nullptr){
        //     if(sln.count(pNode))
        //         return true;
        //     sln.insert(pNode);
        //     pNode = pNode->next;    
        // }
        // return false;

        // METHOD 2:
        if(head == nullptr || head->next==nullptr)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast!=slow)
        {
            if(fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end

