#include <bits/stdc++.h>
using namespace std;

void merge(std::vector<int> &arr,int l,int m,int r){
    int i = l;
    int j = m+1;
    vector<int> temp;
    while(i<=m && j <=r){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else temp.push_back(arr[j++]);
    }
    while(i<=m)
      temp.push_back(arr[i++]);
    
    while(j<=r)
      temp.push_back(arr[j++]);
    
    for(int i=l;i<=r;i++){
        arr[i] = temp[i-l];
    }
}

void mergeSort(vector<int> &arr,int l,int r){
    if(l>=r) return;
    int mid   = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main()
{   vector<int> arr = {3,1,2,4};
    mergeSort(arr,0,arr.size()-1);
    for(auto it:arr) cout << it << " ";
    
    return 0;
}
