#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int n,m;
string answer ="<";
queue <int> q;
bool arr[5001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size() > 1){
        int count = 1;
        while(count<m){
            int number = q.front();
            q.pop();
            q.push(number);
            count++;
        }
        int number = q.front();
        q.pop();
        answer+=to_string(number);
        answer+=", ";
    }
    answer+=to_string(q.front());
    answer+=">";
    cout << answer;
    return 0;
}