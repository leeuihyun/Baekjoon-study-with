#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m,start;
int arr[1001][1001];
bool visited[1001];

void visit_reset(){
    memset(visited,false,sizeof(visited));
}

void dfs(int number){
    visited[number] = true;
    cout << number << " ";
    for(int i=1;i<=n;i++){
        if(arr[number][i] && !visited[i]){
            dfs(i);
        }
    }
}
void bfs(int number){
    queue <int> q;
    visited[number] = true;
    q.push(number);
    while(!q.empty()){
        number = q.front();
        q.pop();
        cout << number << " ";
        for(int i=1;i<=n;i++){
            if(!visited[i] && arr[number][i]){
                visited[i] = true;
                q.push(i);
                
            }
        }
    }    
}
int main(){
    cin >> n >> m >> start;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfs(start);
    cout << "\n";
    visit_reset();
    bfs(start);
    return 0;
}