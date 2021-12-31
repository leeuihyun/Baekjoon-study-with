#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int cases;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> cases;
    while(cases--){
        deque <int> dq;
        int reverse = 1;
        bool err = true;
        string answer = "";
        string judge;
        int number;
        string s;
        cin >> judge;
        cin >> number;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[') continue;
            else if(s[i] >= '0' && s[i] <= '9'){
                answer+=s[i];
            }
            else if((s[i]==']' || s[i]==',') && answer != ""){//
                dq.push_back(atoi(answer.c_str()));
                answer = "";
            }
            
        }
        for(int i=0;i<judge.size();i++){
            if(judge[i]=='R'){
                reverse*=-1;
            }
            else{
                if(dq.empty()){
                    err = false;
                    break;
                }
                else{
                    if(reverse==-1){
                        dq.pop_back();
                    }
                    else{ //뒤집어지지 않았을때
                        dq.pop_front();
                    }
                }
                
            }
        }
        if(err==false){
            cout << "error" << "\n";
            
        }
        else if(dq.empty()){
            cout << "[]" << "\n";
        }
        else{
            cout << "[";
            if(reverse==1){
                while(dq.size()>1){
                    cout << dq.front() << ",";
                    dq.pop_front();
                }
                cout << dq.front();
            }
            else{
                while(dq.size()>1){
                    cout << dq.back() << ",";
                    dq.pop_back();
                }
                cout << dq.back();
            }
            cout << "]" << "\n";
        }
    }
    return 0;
}