#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int number;
int arr[26][26];
bool visited[26][26];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
vector <int> v;

int bfs(int x,int y){
    visited[x][y] = true;
    queue <pair<int,int>> q;
    q.push({x,y});
    int answer = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx >=number || ny < 0 || ny >=number) continue;
            if(arr[nx][ny] && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = true;
                answer+=1;
            }
        }
    }
    return answer;
}

int main(){
    cin >> number;
    for(int i=0;i<number;i++){
        for(int j=0;j<number;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    for(int i=0;i<number;i++){
        for(int j=0;j<number;j++){
            if(arr[i][j] && !visited[i][j]){
                int n = bfs(i,j);
                v.push_back(n);
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    }
    return 0;
}
