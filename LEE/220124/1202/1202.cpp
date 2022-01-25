#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;

vector<pair<long long,long long>> v;
vector<int> my;
priority_queue<long long> pq;

long long answer = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        long long weight,price;
        cin >> weight >> price;
        v.push_back({weight,price});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        int number;
        cin >> number;
        my.push_back(number);
    }
    sort(my.begin(),my.end());
    int idx=0;
    for(int i=0;i<k;i++){
        while(idx < v.size() && v[idx].first <= my[i]){
            pq.push(v[idx++].second);
        }
        if(!pq.empty()){
            answer+=pq.top();
            pq.pop();
        }
    }
    cout << answer;
    return 0;
}