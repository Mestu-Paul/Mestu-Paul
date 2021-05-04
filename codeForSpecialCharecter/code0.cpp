#include <bits/stdc++.h>
using namespace std;
string ch1 = "├",ch3="└",ch2="│",ch4="─";
char c1='+',c2='[',c3='!',c4='-';
pair<string,pair<int,int>> stringCut(string s, int pos){
    string res;
    int dot=0;
    int last;
    for(int i=pos; i<s.size(); i++){
        if(s[i]=='/'){
            last=i+1;break;
        }
        res+=s[i];
        if(s[i]=='.')dot=1;
    }
    return make_pair(res,make_pair(last,dot));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test,cs=1;
    cin>>test;
    while(test--){
        string s;
        vector<string>add;
        bool Break=0;
        cin.ignore();
        while(1){
            getline(cin,s);
            if(s.size()>0){
                string tmp="";
                for(int i=0; i<s.size(); i++){
                    if(s.substr(i,3)==ch1)tmp+=c1,i+=2;
                    else if(s.substr(i,3)==ch2)tmp+=c2,i+=2;
                    else if(s.substr(i,3)==ch3)tmp+=c3,i+=2;
                    else if(s.substr(i,3)==ch4)tmp+=c4,i+=2;
                    else tmp+=s[i];
                }
                add.push_back(tmp);
            }
            if(Break&&s.size()==0)break;
            if(s=="root"){
                Break=1;continue;
            }
        }
        map<pair<int,int>,string>par;
        map<string,bool>isItOk;
        for(int i=0; i<add.size(); i++){
            s = add[i];
            if(s=="root"){
                par[{0,0}]="root";
                continue;
            }
            string tmp="",its_root;
            pair<int,int> start_pos;
            int start=0;
            for(int j=0; j<s.size(); j++){
                if(s[j]==' ')continue;
                if(s[j]==c2){
                    par[{i,j}]=par[{i-1,j}];
                    j+=3;continue;
                }
                if(s[j]==c1){
                    par[{i,j}]=par[{i-1,j}];
                    its_root=par[{i,j}];
                    j+=3;continue;
                }
                if(s[j]==c3){
                    its_root = par[{i-1,j}];
                    j+=3;continue;
                }
                if(start==0){
                    start_pos = make_pair(i,j);
                    start=1;
                }
                tmp+=s[j];
                if(j+1==s.size()){
                    its_root+=tmp;
                    isItOk[its_root]=1;
                    par[start_pos]=its_root;
                    break;
                }
            }
        }
        int qq;
        cin>>qq;
        int cnt=0;
        while(qq--){
            cin>>s;
            if(s.substr(0,6)!="/root/"){
                cnt++;
                continue;
            }
            string now = "root",tmp="";
            int dot,last=6,hobe=1;
            while(1){
                pair<string,pair<int,int>>p=stringCut(s,last);
                dot=p.second.second;
                last=p.second.first;
                tmp=p.first;
                if(dot){
                    if(now=="root"){
                        hobe=0;
                    }
                    break;
                }
                now+=tmp;
                if(!isItOk[now]){
                    hobe=0;break;
                }
            }
            if(!hobe)cnt++;
        }
        cout<<"Case "<<cs++<<": "<<cnt<<endl;
    }
}
