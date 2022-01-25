#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int cases;
int cnt=0;

vector<pair<int,int>> v;
priority_queue<int>pq;

int main(){
    cin >> cases;
    for(int i=0;i<cases;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    int L,P;
    cin >> L >> P;

    int oil = 0;
    int dis = P;//거리
    while(dis < L){
        while(oil < cases && dis >= v[oil].first){
            pq.push(v[oil++].second);
        }
        if(pq.empty()){
            cnt=-1;
            break;
        }
        dis+=pq.top();
        pq.pop();
        cnt+=1;
    }
    cout << cnt;
    return 0;
}