#include <iostream>
using namespace std;
int main(){
    int result = 0;
    int h, w;
    cin>>h>>w;
    int block[501];
    for(int i=0; i<w; i++){
        cin>>block[i];
    }
    
    for(int i=0; i<w-1;){
        int first = block[i];
        int end = -1;
        int end_idx = -1;
        for(int j=i+1; j<w; j++){
            if(block[j] > end) {
                end = block[j];
                end_idx = j;
                if(end > first) break;
            }
        }
        int limit = first;
        if(end < first) limit = end;
        
        for(int j=i+1; j<end_idx; j++){
            int gap = limit - block[j];
            if(gap > 0) result += gap;
        }
        i = end_idx;
    }
    cout<<result<<endl;
}
