#include <iostream>
#include <cmath>

using namespace std;

int cases;

int arr[10001];
int dp[10001];

int main(){
    cin >>cases;
    for(int i=1;i<=cases;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=cases;i++){
        for(int j=1;j<=i;j++){
            dp[i] = max(dp[i],dp[i-j]+arr[j]);
        }
    }
    cout << dp[cases];
    return 0;
}