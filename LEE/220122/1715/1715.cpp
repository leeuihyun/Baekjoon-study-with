#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int cases;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> cases;
    for(int i=0;i<cases;i++){
        int number;
        cin >> number;
        pq.push(number);
    }
    int sum = 0;

    while(pq.size()!=1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum+=(a+b);
        pq.push(a+b);
    }
    cout << sum << "\n";
    return 0;
}