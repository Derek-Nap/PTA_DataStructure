#include <iostream>
#define M 10000
using namespace std;
void print(int data[M]){
    bool ini=true;
    for(int i=M-1;i>=0;i--){
        if(data[i]){
            if(!ini) cout<<" ";
            cout<<data[i]<<" "<<i;
            ini=false;
        }
    }
    if(ini) cout<<"0 0";
    cout<<endl;
}
int main(){
    int a[M]={0};
    int b[M]={0};
    int c[M]={0};
    int d[M]={0};
    int T,coef,expo;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>coef>>expo;
        a[expo]=coef;
    }
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>coef>>expo;
        b[expo]=coef;
    }
    //乘法
    for(int i=M-1;i>=0;i--){
        if(a[i]){
            for(int j=M-1;j>=0;j--){
                if(b[j]){
                    c[i+j]+=(a[i]*b[j]);
                }
            }
        }
    }
    //加法
    for(int i=M-1;i>=0;i--){
        if(a[i]){
            d[i]+=a[i];
        }
    }
    for(int i=M-1;i>=0;i--){
        if(b[i]){
            d[i]+=b[i];
        }
    }
    print(c);
    print(d);
    system("pause");
    return 0;
}