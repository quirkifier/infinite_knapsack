#include<iostream>
#include <vector>
using namespace std;
#define For(i, a, b) for (int i = a; i < b; ++i)
#define rFor(i, a, b) for (int i = a; i >= b; --i)
#define rep(i, N) For(i, 0, N)
#define rRep(i,N) rFor(i, N,0)
using vi = vector<int>;
int recursive(int coins[10],int amount,int profit,int i,int n,int& times)
{
    if(profit == amount)
    {
        times++;
        return 0;
    }
    if(i>=n)
    {
        return 0;
    }
    int choose = 0;
    if(coins[i]+profit<=amount)
    {
        choose = coins[i]+recursive(coins,amount,profit+coins[i],i,n,times);
    }
    int leave = recursive(coins,amount,profit,i+1,n,times);
    return times;
}

int main(){
    int coins[10]={1,2,5};
    int amount = 5;
    int size = 3;
    int times{};
    recursive(coins,amount,0,0,size,times);
    std::cout<<times<<"\n";
}
