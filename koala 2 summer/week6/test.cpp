#include<iostream>
using namespace std;

void recur(int n);

int main(){
  int n;
  cin>>n;
  recurn(n);
  return 0;
  
}

void recur(int n){
  if(n==0) return;
  recur(n-1);
  cout<<n;
  recur(n-1);
  return;
}
