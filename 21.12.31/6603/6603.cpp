#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result[6];
bool visited[50];
vector <int> v;
int n;
void solve(int cur,int idx){
    if(cur==6){
        for(int i=0;i<6;i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=idx;i<n;i++){
        if(visited[v[i]])continue;
        visited[v[i]] = true;
        result[cur] = v[i];
        solve(cur+1,i+1);
        visited[v[i]] = false;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            int number;
            cin >> number;
            v.push_back(number);
        }
        sort(v.begin(),v.end());
        solve(0,0);
        cout << "\n";
        v.erase(v.begin(),v.end());
    }
    return 0;
}