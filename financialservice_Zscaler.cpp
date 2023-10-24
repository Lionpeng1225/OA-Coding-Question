#include<bits/stdc++.h>

using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}


int func(int totalpackets, int n, vector<vector<int>> &uploadedChunks){
    sort(uploadedChunks.begin(), uploadedChunks.end());
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(i == 0){
            if(uploadedChunks[i][0] == 1){
                continue;
            }
            else{
                int diff = uploadedChunks[i][0]-1;
                ans += countSetBits(diff);
            }
        }
        else{
            int diff = uploadedChunks[i][0] - uploadedChunks[i-1][1] - 1;
            ans += countSetBits(diff);
        }

    }
    if(uploadedChunks[n-1][1] == totalpackets){
    }
    else{
        int diff = totalpackets - uploadedChunks[n-1][1];
        ans += countSetBits(diff);
    }

    return ans;
}



int main(){
    int totalpackets;
    cin >> totalpackets;

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> uploadedChunks(n, vector<int> (m));
    for(int i = 0;i<n;i++){
        cin >> uploadedChunks[i][0] >> uploadedChunks[i][1];
    }
  
    cout << func(totalpackets, n, uploadedChunks);

    
    return 0;
}