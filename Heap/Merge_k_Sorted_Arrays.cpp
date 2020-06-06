/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
The first line of input contains the number of test cases, then T test cases follow. Each test case will contain an integer K denoting the number of sorted arrays(each with size K). Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Expected Time Complexity: O(K*K*Log(K) )
Expected Auxiliary Space: O(K*K)
Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
1
3
1 2 3 4 5 6 7 8 9 

Output:
1 2 3 4 5 6 7 8 9

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
*/

typedef pair<int, int> pi;
int *mergeKArrays(int arr[][N], int k)
{
    int *a=new int[k*k];
    int taken[k]={0};
    int i=0;
    priority_queue<pi,vector <pi> ,greater<pi> > pq;
    for(int j=0;j<k;j++){
        pq.push(make_pair(arr[j][0],j));
        taken[j]=1;
    }
    while(!pq.empty()){
        pi p=pq.top();
        pq.pop();
        int in=p.second;
        int val=p.first;
        a[i]=val;
        i++;
        if(taken[in]<k){
            pq.push(make_pair(arr[in][taken[in]],in));
            taken[in]++;
        }
    }
    return a;
}