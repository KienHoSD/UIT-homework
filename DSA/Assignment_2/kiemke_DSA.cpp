/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
map
multi_set
unordered_map
merge
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void heapify(vector<string> &arr, int N, int i)
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

void heap_Sort(vector<string> &arr, int N)
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
    int n; cin>>n;
    string temp;
    cin.ignore();
    vector<string> vec;
    for (int i=0;i<n;i++){
        getline(cin,temp);
        vec.push_back(temp);
    }
    heap_Sort(vec,n);
    int count=1;
    for(int i =0;i<n-1;i++)
        if(vec[i+1]!=vec[i])
            count++;
    cout<<count;
}
