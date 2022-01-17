#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100000

using namespace std;

int arr[MAX+1];
int dp[MAX+1];
int cases;

int answer = 0;
int main(){
    cin >>cases;
    for(int i=0;i<cases;i++){
        cin >> arr[i];  
    }

    for(int i=0;i<cases;i++){
        if(i==0){
            dp[i] = arr[i];
            answer = dp[i];
            continue;
        }
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        answer = max(answer,dp[i]);
    }
    cout << answer;
    return 0;
}