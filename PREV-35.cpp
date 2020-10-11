#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string ss;
//int ans;

void solve(){
    cin>>ss;
    int i, j, k;
    while(true){
        int len = ss.length();
        int st, ed;
        int flag = false;
        for(i=0; i<len; i++){
            if(ss[i]=='(') st=i;
            if(ss[i]==')'){
                ed = i;
                flag=true;
                break;
            }
        }
        if(!flag){
            for(k=0; k<len; k++){
                if(ss[k]=='|') break;
            }
            int gl1 = k, gl2 = len-k-1;
            printf("%d\n", max(gl1, gl2));
            break;
        }else{
            string pt1, pt2;
            for(i=0; i<st; i++) pt1+=ss[i];
            for(i=ed+1; i<len; i++) pt2+=ss[i];
            for(k=st+1; k<ed; k++){
                if(ss[k]=='|') break;
            }
            int gl1 = k-st-1, gl2 = ed-k-1;
            int tp = max(gl1, gl2);
            string pt3;
            while(tp--){
                pt3+='x';
            }
            ss = pt1+pt3+pt2;
//            cout<<ss<<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
