#include <iostream>

using namespace std;

int cases;

int dp[11];
int solve(int number){
    if(number==1)return 1;
    if(number==2)return 2;
    if(number==3)return 4;
    if(dp[number])return dp[number];
    else{
        dp[number] = solve(number-1) + solve(number-2) + solve(number-3);
    }
    return dp[number];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> cases;
    while(cases--){
        int number;
        cin >> number;
        int answer = solve(number);
        cout << answer << "\n";
    }
    return 0;
}