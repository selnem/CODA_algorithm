#include<iostream>
#include<stack>
using namespace std;

int main(){  
    string line;
    cin>>line;
    stack<int> st;
    int cur=0;
    for(int i = 0; i < line.size(); i++){
        char it = line[i];
        if(it == ')'){
            int k= st.top();
            st.pop();
            int m = st.top();
            st.pop();
            cur = m + k *cur;
            
        }
        else if(line[i+1] =='('){
            st.push(cur);
            st.push(it-'0');
            cur=0;
            i++;
        }
        else{
            cur++;
        }
    }
    cout<<cur;

    return 0;
}

