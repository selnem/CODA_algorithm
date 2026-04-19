#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
using namespace std;
bool isPel(string l);

int main(){
    int n;
    cin>>n;
    string line;
	cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(isPel(line)) cout<<'O'<<'\n';
        else cout<<'X'<<'\n';

    }
    return 0;
}

bool isPel(string l){
    queue<char> q;
    stack<char> st;
    for(char it:l){
        if(!(it>='a'&&it<='z')&&!('0'<=it&&it<='9')) continue;
        q.push(it);
        st.push(it);
    }
    int s=q.size();
    s/=2;
    for(int i=0;i<s;i++){
        if(st.top() != q.front()) return false;
        st.pop();
        q.pop();
    }
    return true;
}