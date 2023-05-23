/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}
int main(){
    int n,temp; cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    int *a = vec.data();
    int count =0;
    heapSort(a,n);
    if(vec[0]==0){
        count++;
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]==1)
                count++;
            else if(a[i+1]==a[i]) continue;
            else break;
        }
    }
    cout<<count;
}
