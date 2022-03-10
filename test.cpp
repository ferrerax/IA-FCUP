#include <bits/stdc++.h>
#include <iostream>


using namespace std;


int getInvCount(int arr[], int n)
{
    vector<int> aux(arr, arr + n);

    unsigned int inv_count = 0;
    
    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j++){
            if( (aux[j] < aux[i]) and (aux[j] != 0) )
                inv_count++;
        }
    }

    return inv_count;
}
 
// Driver Code
int main()
{
    int arr[] = { 12, 1, 10, 2, 7, 11, 4, 14, 5, 0, 9, 15, 8, 13, 6, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "
         << getInvCount(arr, n);
    return 0;
}
 
// This code is contributed
// by Akanksha Rai