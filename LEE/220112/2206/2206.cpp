#include <iostream>
#include <queue>

using namespace std;

int n,m;
int arr[1001][1001];
bool visited[1001][1001][2];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int solve(int x,int y){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(x,y),make_pair(1,1))); // x,y,cnt,wall부실수있는횟수
    visited[x][y][1] = true;
    while(!q.empty()){
        x=q.front().first.first;
        y=q.front().first.second;
        int cnt = q.front().second.first;
        int destroy = q.front().second.second;
        q.pop();
        if(x==n-1 && y==m-1) return cnt;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx >= n || ny <0 || ny >=m) continue;
            if(arr[nx][ny] && destroy){
                visited[nx][ny][destroy] = true;
                q.push(make_pair(make_pair(nx,ny),make_pair(cnt+1,destroy-1)));
            }
            if(!arr[nx][ny] && !visited[nx][ny][destroy]){
                visited[nx][ny][destroy] = true;
                q.push(make_pair(make_pair(nx,ny),make_pair(cnt+1,destroy)));
            }          
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    cout <<solve(0,0);
    
    return 0;
}