#include<iostream>
#include<stack>
using namespace std;

int main(){
    string line;
    cin>>line;
    stack<char> st;
    int ans=0;
    for(char it:line){
        if(it == ')'){
            if(st.empty()){
                ans++;
                continue;
            } else {
                st.pop();
            }
        } else {
            st.push(it);
        }
    }
    ans+= st.size();
    cout<<ans;
    return 0;
}