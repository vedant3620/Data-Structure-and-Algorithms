#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y){
	int t=*x;
	*x=*y;
	*y=t;
}

class MinHeap{
	int *harr;
	int capacity;
	int heap_size;
	public:
		MinHeap(int capacity){
			harr=new int[capacity];
			heap_size=0;
			this->capacity=capacity;
		}
		int parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return 2*i+1;
		}
		int right(int i){
			return 2*i+2;
		}
		void heapify(int i){
    		int l = left(i); 
    		int r = right(i); 
		    int smallest = i; 
    		if (l < heap_size && harr[l] < harr[i]) 
        		smallest = l; 
    		if (r < heap_size && harr[r] < harr[smallest]) 
        		smallest = r; 
    		if (smallest!= i) 
    		{ 
        		swap(&harr[i], &harr[smallest]); 
        		heapify(smallest); 
    		}	 
		}
		int extractMin(){
			if (heap_size <= 0) 
			    return INT_MAX; 
			if (heap_size == 1){
			    heap_size--; 
			    return harr[0]; 
			}
		    int root = harr[0]; 
		    harr[0] = harr[heap_size-1]; 
		    heap_size--; 
		    heapify(0); 
		    return root; 
		}
		void decreaseKey(int i,int new_value){
			harr[i]=new_value;
			while(i!=0&&harr[parent(i)]>harr[i]){
				swap(&harr[parent(i)],&harr[i]);
				i=parent(i);
			}
		}
		int getMin(){
			return harr[0];
		}
		void deleteKey(int i){
			decreaseKey(i,INT_MIN);
			extractMin();
		}
		void insertKey(int k){
			if (heap_size == capacity){ 
        		cout << "\nOverflow: Could not insertKey\n"; 
        		return;
			}
			heap_size++;
			int i=heap_size-1;
			harr[i]=k;
			while(i!=0&&harr[parent(i)]>harr[i]){
				swap(&harr[parent(i)],&harr[i]);
				i=parent(i);
			} 
		}
		
		
};

int main() 
{ 
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1);     
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
}
