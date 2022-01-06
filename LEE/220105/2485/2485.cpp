#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int cases;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
vector <int> v;
vector <int> term;
int n;
int answer;
int c2;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> cases;
    c2 = cases;
    while(cases--){
        int number;
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        int t = v[i] - v[i-1];
        term.push_back(t);
    }
    n = gcd(term[0],term[1]);
    for(int i=0;i<term.size();i++){
        n = gcd(n,term[i]);
    }
    for(int i=0;i<c2-1;i++){
        answer += term[i]/n-1;
    }
    cout << answer;

    return 0;
}