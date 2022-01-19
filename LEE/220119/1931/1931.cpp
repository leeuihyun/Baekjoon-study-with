#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int cases;
int answer = 1;

vector <pair<int,int>> v;
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    cin >> cases;
    for(int i=0;i<cases;i++){
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(), compare);
    int _start = v.front().second;
    for(int i=1;i<v.size();i++){
        if(_start <= v[i].first){
            answer+=1;
            _start = v[i].second;
        }
        else{
            continue;
        }
    }
    cout << answer;
    return 0;
}