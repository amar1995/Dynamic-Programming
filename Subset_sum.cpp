#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int set[N+1];
    for(int i =1;i<=N; i++)
        scanf("%d",&set[i]);
    
    int sumreq;
    scanf("%d",&sumreq);

    bool DP[N+1][sumreq+1];
    for(int i =0;i<=N;i++){
        for(int j= 0; j<=sumreq; j++){
            if(j == 0 )
                DP[i][j] = true;
            else if(i == 0)
                DP[i][j] = false;
            else if(j < set[i])
                DP[i][j] = DP[i-1][j];
            else       
                DP[i][j] = max(DP[i-1][j],DP[i-1][j-set[i]]);
        }
    }
    int temp = sumreq; 
    //Weights and values involved
    for(int i = N; i>0; i--){
        if(DP[i-1][temp] != DP[i][temp]){
            temp = temp - set[i];
            printf("%d\n",set[i]);
        }
    }
    return 0;
}