#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int number;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> number;
    for(int i=0;i<number;i++){
        int a;
        cin >> a;
        if(a!=0){
            pq.push(a);
        }
        else if(a==0){
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else{
                cout << "0" << "\n";
            }
        }
    }    
return 0;
}