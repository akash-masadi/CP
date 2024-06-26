#include<bits/stdc++.h>
using namespace std;

int normal_fibo(int n){ // O(2^n) time complexity
    if(n==0 || n==1){
        return n;
    }
    return normal_fibo(n-1)+normal_fibo(n-2);
}

int iter_fibo(int n){ // O(n) time complexity
    if(n==0 || n==1){
        return n;
    }
    int a=0,b=1;
    for(int i=2;i<=n;i++){
        int c=a+b;
        a=b;
        b=c;
    }
    return b;
}

#define mod 1000000007
void multiply(int f[2][2],int m[2][2])
{
    int a00=( (f[0][0]*1ll*m[0][0])%mod + (f[0][1] *1ll *m[1][0])%mod)%mod ;
    int a01= ((f[0][0]*1ll*m[0][1])%mod + (f[0][1]*1ll*m[1][1])%mod)%mod ;
    int a10= ( (f[1][0]*1ll*m[0][0])%mod+ (f[1][1]*1ll*m[1][0])%mod )%mod;
    int a11= ((f[1][0]*1ll*m[0][1])%mod + (f[1][1]*1ll*m[1][1])%mod)%mod;
    f[0][0]=a00;
    f[0][1]=a01;
    f[1][0]=a10;
    f[1][1]=a11;
}
void power(int f[2][2],int n)
{
    if(n<=1)
    {
        return ;
    }
    power(f,n/2);
    multiply(f,f);
    if( (n%2) !=0 )
    {
        int m[2][2]={{1,1},{1,0}};
        multiply(f,m);
    }
}
int fibo(int n){ // O(logn) time complexity
    if(n==0 || n==1){
        return n;
    }
    int F[2][2]={{1,1},{1,0}};
    power(F,n-1);
    return F[0][0];
}

int main(){
    int n=0;
    while(n<10)
        cout<<fibo(n++)<<'\n';
    return 0;
}