#include <iostream>
#include <vector>


using namespace std;

int n,m;
vector <int> v;
int answer = 0;
void solve(int cur,int sum){
    if(cur==n)return;
    if(v[cur] + sum == m) answer+=1;
    solve(cur+1, sum);
    solve(cur+1, sum+v[cur]);
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        v.push_back(number);
    }
    solve(0,0);
    cout << answer;
    return 0;
}