#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    int sum=-1,temp=0,templeftindex=0,indexleft=0,indexright=n-1;//不需要rightindex因为可以用i赋值
    vector<int> a(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        temp=temp+a[i];
        if(temp<0){
            temp=0;
            templeftindex=i+1;//从右边开始数一数
        } else if(temp>sum){//成功一次，记录最左边的index
            sum=temp;
            indexleft=templeftindex;
            indexright=i;
        }
    }

    if(sum<0) sum=0;
    printf("%d %d %d",sum,a[indexleft],a[indexright]);
    return 0;

}