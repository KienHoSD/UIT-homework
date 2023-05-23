#include <iostream>
#include <algorithm>
#include <vector>
struct point{
    int x,y;
};
bool operator>(point const &kieu,point const &phong){
    if(kieu.x>phong.x) return true;
    if(kieu.x==phong.x)
        if(kieu.y<phong.y) return true;
    return false;
}
void heapify(std::vector<point> &arr, int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heap_bort(std::vector<point> &arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main(){
    int n; std::cin>>n;
    //point *a = new point[n];
    std::vector<point> a;
    for(int i=0;i<n;i++){
        point temp;
        std::cin>>temp.x>>temp.y;
        a.push_back(temp);
    }
    heap_bort(a,n);
    for(int i=0;i<n;i++) std::cout<<a[i].x<<" "<<a[i].y<<"\n";
}
