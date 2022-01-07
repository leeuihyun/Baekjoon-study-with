#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int number;
int arr[81];
string t;
bool solvetorf = false;
void solve(int cur,string ss){
    if(solvetorf==true)return;  
    if(cur > number) return;
    for(int i=1;i<=ss.size()/2;i++){
        string first = ss.substr(ss.size()-i,i);
        string second = ss.substr(ss.size()-(2*i),i);
        if(first==second){
            return;
        }
    }
    if(cur==number){
        solvetorf = true;
        cout << ss;
        return;
    }
    for(int i=0;i<number;i++){
        solve(cur+1,ss+"1");
        solve(cur+1,ss+"2");
        solve(cur+1,ss+"3");
    }
}
int main(){
    cin >> number;
    solve(0,t);
    return 0;
}