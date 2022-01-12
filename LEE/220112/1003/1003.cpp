#include <iostream>

using namespace std;

int cases;

int zero[41];
int one[41];
int fibo_zero(int number){
    
    if(number==0){
        return 1;
    }
    if(number==1){
        return 0;
    }
    if(zero[number])return zero[number];
    zero[number]= fibo_zero(number-1)+fibo_zero(number-2);
    return zero[number];
}
int fibo_one(int number){
    if(number==0){
        return 0;
    }
    if(number==1){
        return 1;
    }
    if(one[number])return one[number];
    one[number]= fibo_one(number-1)+fibo_one(number-2);
    return one[number];
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>cases;
    while(cases--){
        int number;
        cin >> number;
        cout << fibo_zero(number) << " " << fibo_one(number) <<"\n";
    }
    return 0;
}