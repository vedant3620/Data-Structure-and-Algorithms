/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/

typedef pair<ListNode *,int> pi;
struct comp{
    bool operator()(pi a,pi b){
        return a.first->val>=b.first->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        priority_queue<pi,vector<pi >,comp> pq;
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)pq.push(make_pair(lists[i],i));
            // lists[i]=lists[i]->next;
        }
        if(pq.size()==0)return NULL;
        ListNode *root=pq.top().first;
        ListNode *curr=NULL;
        while(!pq.empty()){
            pi p=pq.top();
            if(curr==NULL){
                curr=p.first;
            }  
            else{
                curr->next=p.first;
                curr=curr->next;
            }
            lists[p.second]=p.first->next;
            pq.pop();
            if(lists[p.second]!=NULL){
                pq.push(make_pair(lists[p.second],p.second));
            }
        }
        curr->next=NULL;
        return root;
    }
};