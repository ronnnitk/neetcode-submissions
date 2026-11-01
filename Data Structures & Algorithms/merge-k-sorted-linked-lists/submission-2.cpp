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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergehelp(lists,0,lists.size()-1);
    }
    ListNode* mergehelp(vector<ListNode*>& lists, int start,int end){
        if(start==end){
            return lists[start];
        }
        if(start+1==end){
            return merge2Lists(lists[start],lists[end]);
        }
        int mid =start +(end-start)/2;
        ListNode* left= mergehelp(lists,start,mid);
        ListNode* right= mergehelp(lists,mid+1,end);

        return merge2Lists(left,right);
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* dummy =new ListNode(0);
        ListNode* curr=dummy;

        while(l1!=NULL && l2!= NULL){
            if(l1->val < l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next = (l1!=NULL) ?  l1 : l2;
        return dummy->next;
    }
};
