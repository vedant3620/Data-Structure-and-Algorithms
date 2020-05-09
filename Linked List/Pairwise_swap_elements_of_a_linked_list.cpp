/*
Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains linked list data.

Output:
Output the linked list after swapping pairwise nodes.

User Task:
The task is to complete the function pairWiseSwap() which takes head node as the only argument and returns the modified head.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
1
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7

Explanation:
Testcase 1: After swapping each pair considering (1,2), (2, 4), (5, 6).. so on as pairs, we get 2, 1, 4, 2, 6, 5, 8, 7 as new linked list.
*/


Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    if(head==NULL||head->next==NULL)return head;
    Node *nxt=head->next;
    head->next=pairWiseSwap(nxt->next);
    nxt->next=head;
    return nxt;
}