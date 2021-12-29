#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number;
vector <pair<int,int>> v;

bool compare(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second < b.second;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;  
    for(int i=0;i<number;i++){
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " <<  v[i].second << "\n";
    }
    return 0;
}