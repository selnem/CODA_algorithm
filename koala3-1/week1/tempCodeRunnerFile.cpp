#include<iostream>
using namespace std;

string line;
int main(){  
    cin>>line;
    int ans = 0;
    int a;
    stack<char> st;
    for(char it:line){
        if(it == ')'){
            while(!st.empty()){
                if(st.top()=='('){
                    st.pop();
                    break;
                }
                ans++;
            }
            ans*=st.top()-'0';
            st.pop();
        }
        else{
              st.push(it);
       }
    }
    ans+=st.size();
    cout<<ans;
    
    return 0;
}

