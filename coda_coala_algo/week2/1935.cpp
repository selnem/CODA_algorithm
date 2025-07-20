#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    double arr[26]={0};
    stack<double> s;
    string cmd;
    int N;
    cin>>N;
    cin>>cmd;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(auto c:cmd){
        if('A'<=c&&c<='Z'){
            s.push(arr[c-'A']);
        }
        else{
            double b=s.top();
            s.pop();
            double a=s.top();
            s.pop();
            double ans;
            
            switch(c){
                case '+':
                    ans=a+b;
                    break;
                case '-':
                    ans=a-b;
                    break;
                case '*':
                    ans=a*b;
                    break;
                case '/':
                    ans=a/b;
                    break;
                default:
                    break;
            }
            s.push(ans);
        }
    }   
    cout<<fixed;
    cout.precision(2);
    cout<<s.top();
    return 0;
}