#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int row_size = land.size();
    int dp[row_size][4];
    for(int i=0; i<4; i++){
        dp[0][i] = land[0][i];
    }
    for(int i=1; i<row_size; i++){
        for(int j=0; j<4; j++){
            int step = 0;
            for(int k=0; k<4; k++){
                if(j != k && step < dp[i-1][k]){
                    step = dp[i-1][k];
                }
            }
            dp[i][j] = step + land[i][j];
        }
    }
    
    for(int i=0; i<4; i++){
        if(dp[row_size - 1][i] > answer){
            answer = dp[row_size - 1][i];
        }
    }

    return answer;
}