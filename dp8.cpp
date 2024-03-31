#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool subsetSum(int arr[], int n, int sum) {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        
        // If the current element is greater than the sum, skip it
        if (arr[n - 1] > sum)
            return subsetSum(arr, n - 1, sum);
        
        // Check if either including or excluding the current element leads to the desired sum
        return subsetSum(arr, n - 1, sum - arr[n - 1]) || subsetSum(arr, n - 1, sum);
    }

    bool equalPartition(int N, int arr[]) {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
        
        // If sum is odd, it can't be divided into two equal partitions
        if(sum % 2 != 0)
            return false;
        
        // Check if there exists a subset with sum equal to sum/2
        return subsetSum(arr, N, sum / 2);
    }
};

int main(){
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
