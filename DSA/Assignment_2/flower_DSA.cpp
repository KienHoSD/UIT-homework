#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::find;
using std::swap;
using std::distance;
using std::endl;

void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap

void heap(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
void heapify(vector<int> &arr, int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap

void heap(vector<int> &arr, int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main(){
    int n,k,temp;cin>>n>>k;
    int arr2[100000];
    for (int i=0;i<n;i++){
        cin>>arr2[i];
    }
    if(n<=k) for(int i=0;i<n;i++) cout<<arr2[i]<<" ";

    else{
        vector<int> a;
        int m=0;
        heap(arr2,n);
        int e=0;
        while(e<k){
            for(int i=0;i<n-1;i++){
                if(arr2[i]!=arr2[i+1]&&arr2[i]!=0){

                    a.push_back(arr2[i]);
                    arr2[i]=0;
                    e++;
                    if(e>=k) break;
                }
            }
            if(e>=k) break;
            for(int i=n-1;i>0;i--){
                if(arr2[i]!=arr2[i-1]&&arr2[i]!=0){

                    a.push_back(arr2[i]);
                    arr2[i]=0;
                    e++;
                    if(e>=k) break;
                }
            }
        }
        heap(a,e);
        for (int i:a) cout<<i<<" ";
    }
    return 0;
}//10 4 1 3 5 2 4 2 3 4 10 11
