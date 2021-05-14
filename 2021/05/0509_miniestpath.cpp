#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int m,n,k;
struct move1{
    int x0;
    int y0;
    int x1;
    int y1;
    int daijia;
    bool operator <(const move1& rhs) const{
        if(x0!=rhs.x0){
            return x0<rhs.x0;
        }
        else{
            return y0<rhs.y0;
        }
    }
};
vector<move1>s;

void find(int i,int &dai,int curdai){
    if(s[i].x1==m&&s[i].y1==n){
        if(curdai+s[i].daijia<dai)
            dai=curdai+s[i].daijia;
    }
    else{
        if(s[i].x1>=s[i].x0||s[i].y1>=s[i].y0){
            for(int j=i+1;j<k;++j){
                if(s[j].x0==s[i].x1&&s[j].y0==s[i].y1){
                    curdai+=s[i].daijia;
                    find(j,dai,curdai);
                    curdai-=s[i].daijia;
                }
            }
        }
    }
}

int main(){
    cin>>m>>n>>k;
    int x0,x1,y0,y1,cost;
    for(int i=0;i<k;++i){
        cin>>x0>>y0>>x1>>y1>>cost;
        struct move1 x={x0,y0,x1,y1,cost};
        s.emplace_back(x);
    }
    int ener=10e6;
    sort(s.begin(),s.end());
    for(int i=0;i<k;i++){
        if(s[i].x0==1&&s[i].y0==1)
            find(i,ener,0);
    }
    cout<<ener<<endl;
    return 0;
}
