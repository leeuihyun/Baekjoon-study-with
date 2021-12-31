#include <iostream>
#include <stack>

using namespace std;

int n;

stack <int> st;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s=="push"){
            int number;
            cin >> number;
            st.push(number);
        }   
        else if(s=="top"){
            if(st.size()==0){
                cout << "-1" << "\n";
            }
            else{
                cout << st.top() << "\n";
            }
        }   
        else if(s=="size"){
            cout << st.size() << "\n";
        }  
        else if(s=="empty"){
            if(st.empty()){
                cout << "1" << "\n";
            }
            else{
                cout << "0" << "\n";
            }
        }
        else if(s=="pop"){
            if(st.size()==0){
                cout << "-1" << "\n";            
            }
            else{
                int number = st.top();
                st.pop();
                cout << number << "\n"; 
            }
        }   
    }
    return 0;
}