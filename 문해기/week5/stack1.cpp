#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    for(int i=0;i<5;i++){
        st.push(i);
    }
    for(int i=0;i<st.size();i++){
        cout<<st.top()<<' ';
        st.pop();
    }
}