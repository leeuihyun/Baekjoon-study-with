#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n,m;
int arr[51][51];
bool visited[51];

vector <pair<int,int>> house;
vector <pair<int,int>> chicken;
int answer=INT_MAX;
void solve(int cur,int dep){
    if(dep == m){
        int sum = 0;
        for(int i=0;i<house.size();i++){         
            int min_num = INT_MAX;
            for(int j=0;j<chicken.size();j++){
                if(!visited[j]) continue;
                min_num = min(min_num, abs(chicken[j].first -house[i].first) + abs(chicken[j].second - house[i].second));
            }
            sum+=min_num;
        }
        answer = min(answer,sum);
        return;
    }
    for(int i=cur;i<chicken.size();i++){
        if(visited[i])continue;
        visited[i]=true;
        solve(i+1,dep+1);
        visited[i] = false;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1)house.push_back({i,j});
            if(arr[i][j]==2)chicken.push_back({i,j});
        }
    }
    solve(0,0);//cur,depth
    cout << answer;

    return 0;
}