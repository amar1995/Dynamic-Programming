#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int wt[N],val[N];
    for(int i=0;i<N;i++)
        scanf("%d %d",&wt[i], &val[i]);
    int totalwt;
    scanf("%d",&totalwt);
    int DP[N+1][totalwt+1];
    for(int i =0;i<=N; i++){
        for(int j = 0; j<=totalwt; j++){
            if(i == 0 || j == 0)
                DP[i][j] = 0;
            else if(j < wt[i])
                DP[i][j] = DP[i-1][j];
            else 
                DP[i][j] = max(DP[i-1][j], val[i] + DP[i-1][j-wt[i]]);
        }
    }

    int temp = totalwt; 
    printf("Total Value : %d\n",DP[N][temp]);
    //Weights and values involved
    for(int i = N; i>0; i--){
        if(DP[i-1][temp] != DP[i][temp]){
            temp = DP[i][temp - wt[i]];
            printf("%d %d\n",wt[i],val[i]);
        }
    }
}