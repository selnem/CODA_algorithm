#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MyPage{
    private:
        vector<int> priv;
        stack<int> next;
        int current;
        bool is_start;
    public:
        MyPage(){current=0;is_start=false;};
        void goPriv(){
            if(!is_start||priv.size()<=0){
                return;
            }
            next.push(current);
            current=priv.back();
            priv.

        }


};



int main(){

}