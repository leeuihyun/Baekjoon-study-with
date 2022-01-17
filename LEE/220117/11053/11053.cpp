#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int cases;
int dp[10001];
vector <int> v;
int answer;

int main(){
    cin >> cases;
    for(int i=0;i<cases;i++){
        int num;
        cin >> num;
        v.push_back(num);
        int cnt = 0;

        for(int j=0;j<v.size();j++){
            if(v[j] < v[i]){
                cnt = max(cnt, dp[j]);
            }
        }
        dp[i] = cnt+1;
        answer = max(answer,dp[i]);
    }
    cout <<answer;
    return 0;
}