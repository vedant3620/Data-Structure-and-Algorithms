/*
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of elements in Linked List.
The second line of each test case contains N input,elements in Linked List.

Output:

Print the all even numbers then odd numbers in the modified Linked List.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ size of elements ≤ 1000

Example:

Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
class LinkedList{
    typedef struct node{
        ll data;
        struct node * next; 
        node(ll x){
            data=x;
            next=NULL;
        }
    }Node;
    
    Node * head;
    Node * last;
    public:
    LinkedList(){
        head=NULL;
        last=NULL;
    }
    
    void createList(ll n){
        while(n--){
            ll val;
            cin>>val;
            if(head==NULL){
                Node * temp=new Node(val);
                head=temp;
                last=head;
            }
            else{
                Node * temp=new Node(val);
                last->next=temp;
                last=last->next;
            }
        }
    }
    void print(){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    void segregate1(){
        Node *evens=NULL,*odds=NULL,*evene=NULL,*odde=NULL;
        while(head!=NULL){
            if((head->data%2)==0){
                if(evens==NULL){
                    evens=head;
                    evene=head;
                }
                else{
                    evene->next=head;
                    evene=evene->next;
                }
            }
            else{
                if(odds==NULL){
                    odds=head;
                    odde=head;
                }
                else{
                    odde->next=head;
                    odde=odde->next;
                }
            }
            head=head->next;
        }
        if(odde!=NULL){
            odde->next=NULL;
        }
        else{
            evene->next=NULL;
        }
        if(evene!=NULL){
            evene->next=odds;
        }
        if(evens==NULL)head=odds;
        else head=evens;
    }
};

int main() {
    SPEED;
    //CODE
	test(){
		int n;
		cin>>n;
		LinkedList l;
		l.createList(n);
		l.segregate1();
		l.print();
	}
	return 0;
}