#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int solve(int number){
    if(number==1){
        return 0;
    }
    if(dp[number])return dp[number];
    int n = solve(number-1)+1;
    if(number%3==0){
        n = min(n,solve(number/3)+1);
    }
    if(number%2==0){
       n = min(n,solve(number/2)+1);
    }
    dp[number] = n;
    return dp[number];
}
int main(){
    int number;
    cin >> number;
    cout << solve(number);
    return 0;
}