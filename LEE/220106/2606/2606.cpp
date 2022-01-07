#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool visited[101];
int arr[101][101];
int cnt;
int solve(int number){
    queue<int> q;
    q.push(number);
    visited[number] = true;
    while(!q.empty()){
        number = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(!visited[i] && arr[number][i]){
                visited[i] = true;
                q.push(i);
                cnt+=1;
            }
        }
    }
    return cnt;
}
int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    cout << solve(1);
    return 0;
}