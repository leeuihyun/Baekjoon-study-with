#include <iostream>

using namespace std;
int cases;
int arr[1001];
int answer;
int main(){
    cin >> cases;
    for(int i=2;i<1001;i++) arr[i] = i;
    for(int i=2;i<1001;i++){
        if(arr[i]==0) continue;
        for(int j=i+i;j<1001;j+=i){
            arr[j] = 0;
        }
    }
    while(cases--){
        int number;
        cin >> number;
        if(arr[number])answer+=1;
    }
    cout << answer;
    return 0;
}