#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cases;
int cnt;
bool visited[1001];

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)  return a.first > b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    
    cin >> cases;
    while(cases--){
        vector <pair<int,int>> v;
        int book, student;
        cin >> book >> student;
        for(int i=0;i<student;i++){
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            int left = v[i].first;
            int right = v[i].second;
            for(int j = left;j<=right;j++){
                if(visited[j])continue;
                visited[j] = true;
                cnt+=1;
                break;
            }
        }
        
        cout << cnt << "\n";
        cnt=0;
        memset(visited,false,sizeof(visited));
    }
    return 0;
}
