#include<iostream>
#include<stack>
using namespace std;

typedef pair<int,int> pp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }

    vector<pp> ans(n+2,{0,0});
    stack<pp> l,r;
   
    r.push({n-1,arr[n-1]});
    for(int i=n-2;i>=0;i--){
        if(arr[i]>=arr[i+1]){
            while (!r.empty()&&arr[i]>=r.top().second){
                r.pop();
            }
        }

        ans[i].first += r.size();
        if (!r.empty()) ans[i].second = r.top().first;

        r.push({i,arr[i]});
    }


    l.push({0,arr[0]});

    for (int i = 1; i < n; i++){
        if (arr[i] >= arr[i - 1]){
             while (!l.empty() && arr[i] >= l.top().second) l.pop();
        }
           
        ans[i].first += l.size();
        if (!l.empty() && (ans[i].second == 0 || abs(ans[i].second - i) >= abs(i - l.top().first)))
            ans[i].second = l.top().first;

        l.push({i, arr[i]});
    }
    
  for (int i = 0; i < n; i++){
        if (ans[i].first == 0) cout << 0 << '\n';

        else cout << ans[i].first << ' ' << ans[i].second + 1 << '\n';
    }
    return 0;
}