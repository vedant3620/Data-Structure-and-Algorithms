#define pi pair<int,int>
#define mp make_pair
#define SPEED cin.tie(0)

int temp;
bool isSafe(vector <int> * A,int i,int j,int N,int M,vector <vector<bool>> &visited){
    return ((i<N)&&(i>=0)&&(j<M)&&(j>=0)&&(visited[i][j]==false)&&A[i][j]==1);
}
void dfs(vector <int> A[],int x,int y,int N,int M,vector <vector<bool>> &visited){
    int dir[2][8]={
        {-1,-1,-1,0,0,1,1,1},
        {-1,0,1,-1,1,-1,0,1}
    };
    visited[x][y]=true;
    for(int i=0;i<8;i++){
        if(isSafe(A,x+dir[0][i],y+dir[1][i],N,M,visited))
            dfs(A,x+dir[0][i],y+dir[1][i],N,M,visited);
    }
}

int findIslands(vector<int> A[], int N, int M) {
    int k=0;
    vector <vector<bool> > visited(N,vector<bool> (M,false));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]==1&&visited[i][j]==false){
                dfs(A,i,j,N,M,visited);
                k++;
            }
        }
    }
    visited.clear();
    return k;
}
