#include<iostream>
using namespace std;

struct Fx{
    int x2,x1,con;
};
Fx fX,gX;
inline int judgeFunc(const Fx &fun);
void ans();
Fx synFunc(const Fx&f,const Fx&g);
int main(){    
   
    gX.x2=0;
    cin>>fX.x2>>fX.x1>>fX.con;
    cin>>gX.x1>>gX.con;
    ans();
    return 0;

}


Fx synFunc(const Fx&f,const Fx&g){
    int x2,x1,con;
    x2=f.x2*(g.x1*g.x1)+f.x1*g.x2;
    x1=f.x2*(g.x1*g.con*2)+f.x1*g.x1;
    con=f.con+f.x1*g.con+f.x2*(g.con*g.con);
    Fx syn={x2,x1,con};
    return syn;
}



void ans(){
    const char* ansStr[4]={"Nice", "Go ahead", "Remember my character", "Head on"};
    Fx p=synFunc(fX,gX);
    Fx q=synFunc(gX,fX);
    Fx ans={p.x2-q.x2,p.x1-q.x1,p.con-q.con};
    if(ans.x2==0&&ans.x1==0){
        if(ans.con) cout<<ansStr[3];
        else cout<<ansStr[0];
        return;
    }
    if(ans.x2==0){
        cout<<ansStr[2];
        return;
    }
    int judge=judgeFunc(ans);
    if(judge>0) cout<<ansStr[1];
    else if (judge==0) cout<<ansStr[2];
    else if(judge<0) cout<<ansStr[3];        
    return ;
}
inline int judgeFunc(const Fx &fun){
    return (fun.x1*fun.x1)-4*fun.con*fun.x2;
}



