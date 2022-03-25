
// BOJ Numbers are easy
// 문제 링크: https://www.acmicpc.net/problem/11322

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

inline bool chk(ll cur, ll val){
    return cur%val==0;
}

void bfs(ll val){
    vector<string> nums={"0","1"};
    queue<string> q;
    
    q.push("0");
    q.push("1");
    
    while(!q.empty()){
        string front = q.front();
        q.pop();
        ll current = stoll(front);
        if(current==0LL){
            continue;
        }
        
        if(chk(current,val)){
            cout<<current<<'\n';
            return;
        }
        
        for(int i=0;i<2;++i){
            q.push(front+nums[i]);
        }
        
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    ll val;
    
    cin>>tc;
    
    while(tc--){
        cin>>val;
        bfs(val);
    }
    
    return 0;
}
