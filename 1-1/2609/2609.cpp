#include <iostream>

using namespace std;

int n,m;

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int lgd(int x,int y){
    return x*y/gcd(x,y);
}

int main(){
    cin >> n >> m;
    cout << gcd(n,m) << "\n";
    cout << lgd(n,m);
    return 0;
}