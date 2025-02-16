#include<iostream>
#include <vector>
using namespace std;
#define For(i, a, b) for (int i = a; i < b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; --i)
#define rep(i, N) For(i, 0, N)
#define rRep(i,N) rFor(i, N,0)
#define v vector
int recursive(int coins[10],int amount,int profit,int i,int n,int& times,vector<vector<int>> &memo)
{
    //initialize it with -1
    if(memo[i][profit]!=-1)
    {
        return memo[i][profit];
    }
    if(profit == amount)
    {
        return 1;
    }
    if(i>=n)
    {
        return 0;
    };
    int choose = 0;
    if(profit+coins[i]<=amount)
    {
        choose = recursive(coins,amount,profit+coins[i],i,n,times,memo);
    }
    int leave = recursive(coins,amount,profit,i+1,n,times,memo);
    return memo[i][profit] = choose + leave;
}

int main(){
    int coins[10]={1,2,5};
    int amount = 6  ;
    int size = 3;
    v<v<int>> memo(size+1,v<int>(amount+1,0));
    v<int> memo2(amount+1,0);
    memo2[0] = 1;
    int times{};
    For(i,1,size+1)
    {
        For(j,1,amount+1)
        {
            if(j>=coins[i-1])
            {
                memo2[j]= memo2[j]+memo2[j-coins[i-1]];
            }
        }
    }
    std::cout<<memo2[amount]<<endl;
    /*
    For(i,0,size+1)
    {
        For(j,0,amount+1)
        {
            cout<<memo[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";*/
}
