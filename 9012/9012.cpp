#include <iostream>

using namespace std;

int cases;

int main(){
    cin >> cases;
    while(cases--){
        string s;
        cin >> s;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count+=1;    
            }
            else{
                count-=1;
            }
            if(count<0){
                break;
            }
        }
        if(count!=0){
            cout << "NO" << "\n";
        }
        else cout << "YES" << "\n";
    }
    return 0;
}