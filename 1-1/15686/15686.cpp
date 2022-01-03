#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;
int n,m;

int arr[51][51];
vector <pair<int,int>> house;
vector <pair<int,int>> chicken;
vector <int> v;
int real_answer = INT_MAX;
void solve(){
    do{
        vector<pair<int,int>> vec;
        int sum = 0;
        
        for(int i=0;i<chicken.size();i++){
            if(v[i]==1) vec.push_back({chicken[i].first,chicken[i].second});
        }
        for(int i=0;i<house.size();i++){
            int answer = INT_MAX; // INT_MAX;
            int distance = INT_MAX;
            for(int j=0;j<m;j++){
                distance = abs(vec[j].first - house[i].first) + abs(vec[j].second - house[i].second);
                answer = min(answer, distance);
            }
            sum+=answer;
        }
        real_answer = min(real_answer, sum);
    }while(prev_permutation(v.begin(),v.end()));
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1)house.push_back(make_pair(i,j));
            else if(arr[i][j]==2)chicken.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<m;i++) v.push_back(1);
    for(int i=m;i<chicken.size();i++) v.push_back(0);
    solve();
    cout << real_answer;
    return 0;    
}