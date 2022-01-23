#include<bits/stdc++.h>
using namespace std;

int maxN = 1000000;
int arr[1000000+1];
int pp[1000000+1];

void seive(){
    for (int i = 0; i <= maxN; i++)
    {
        arr[i]=1;
        //pp[i]=0;
    }
    arr[0]=arr[1]=0;
    for (int i = 2; i*i <= maxN; i++)
    {
        if(arr[i]==1){
            for (int j = i*i; j <= maxN; j+=i)
            {
                arr[j]=0;
            }
            
        }
    }
    int cnt = 0;
    for (int i = 0; i <= maxN; i++)
    {
        
        if(arr[i]==1){
            cnt++;
        }
        if(arr[cnt]==1){
            pp[i]=1;
        }else{
            pp[i]=0;
        }
    }
    for (int i = 0; i <= maxN; i++)
    {
        pp[i] += pp[i-1];
    }
    
    
}


int main(int argc, char const *argv[])
{
    seive();
    int a,b,c;
    cin>>a;
    while(a--){
        cin>>b>>c;
        cout<<pp[c]-pp[b-1]<<endl;
    }
    return 0;
}
