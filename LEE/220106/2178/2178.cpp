#include <iostream>
#include <queue>

using namespace std;

int n,m;

int arr[101][101];
bool visited[101][101];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int solve(int x,int y){
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(x,y),1));
    visited[x][y] = true;
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(x==n-1 && y==m-1){
            return cnt;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m)continue;
            if(!visited[nx][ny] && arr[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx,ny), cnt+1));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << solve(0,0);
    return 0;
}