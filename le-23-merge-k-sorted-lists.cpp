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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
            bool(*)(ListNode*, ListNode*)> listq(comp, lists);
        ListNode *head = nullptr, *tail, *top;
        while (!listq.empty()) {
            top = listq.top();
            listq.pop();
            if (top == nullptr)
                continue;
            if (head == nullptr) {
                head = new ListNode(top->val);
                tail = head;
            } else {
                tail->next = new ListNode(top->val);
                tail = tail->next;
            }
            if (top->next != nullptr)
                listq.push(top->next);
        }
        return head;
    }

private:
    static bool comp(ListNode *a, ListNode *b) {
        return (a && b) ? (a->val > b->val) : (b != nullptr);
    }
};