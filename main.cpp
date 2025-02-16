#include <iostream>
#include<vector>
#define v std::vector
#define ref(i,k,n) for(int i =k;i<=n;i++)
int recursive(int arr[],int weight[],int volume[],int N,int totalWeight,int totalVolume,int i,int profit,int weightLimit,int volumeLimit,v<v<v<int>>> &memo)
{
    if(memo[i][totalWeight][totalVolume]!=-1){
        return memo[i][totalWeight][totalVolume];
    }
    if(i>=N) {
        std::cout<<"called\n";
        return 0;
    }
    int choose = 0;
    if(weight[i]+totalWeight<=weightLimit&&totalVolume+volume[i]<=volumeLimit) {
        choose = arr[i] + recursive(arr,weight,volume,N,totalWeight+weight[i],totalVolume+volume[i],i,profit+arr[i],weightLimit,volumeLimit,memo);
    }
    int leave = recursive(arr,weight,volume,N,totalWeight,totalVolume,i+1,profit,weightLimit,volumeLimit,memo);
    return memo[i][totalWeight][totalVolume] = std::max(leave,choose);
}

int main()
{

    int arr[7]={5,10};
    int weight[7]={10,10};
    int volume[7]={10,10};
    int weightLimit = 40;
    int volumeLimit = 40;
    int size = 2;
    v<v<v<int>>> memo(size+1,v<v<int>>(weightLimit+1,v<int>(volumeLimit+1,0)));
    v<v<int>> memo1(weightLimit+1,v<int>(volumeLimit+1,0));
    v<v<int>> memo2(weightLimit+1,v<int>(volumeLimit+1,0));
    int skip;
    int temp = 0;
    ref (i,1,size)
    {
        ref (j,1,weightLimit)
        {
            ref (k,1,volumeLimit)
            {
                if(j>=weight[i-1]&&k>=volume[i-1])
                {
                    memo1[j][k] = std::max(arr[i-1]+memo1[j-weight[i-1]][k-volume[i-1]], memo1[j][k]);
                }
            }
          }
        }
    std::cout<<memo1[weightLimit][volumeLimit]<<"\n";
}
/*
v<v<v<int>>> memo(size+1,v<v<int>>(weightLimit+1,v<int>(volumeLimit+1,0)));
int skip;
ref (i,1,size)
{
ref (j,1,weightLimit)
{
ref (k,1,volumeLimit)
{
if(j>=weight[i-1]&&k>=volume[i-1])
{
memo[i][j][k] = std::max(arr[i-1]+memo[i][j-weight[i-1]][k-volume[i-1]],memo[i-1][j][k]);
}else
{
memo[i][j][k]= memo[i-1][j][k];
}
}
}
}
std::cout<<memo[size][weightLimit][volumeLimit]<<"\n";*/