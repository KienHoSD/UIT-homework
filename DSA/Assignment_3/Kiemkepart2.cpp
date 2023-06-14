#include <iostream>
#include <strings.h>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
using std::string;
struct mavasolan{
    string code;
    int solanxuathien=0;
};
bool cmp2str(string a,string b){
    int daia=a.length(),daib=b.length();
    if(daia==daib){
        for(int i=0;i<daia;i++){
            if(int(a[i])>int(b[i])) return true;
            if(int(a[i])<int(b[i])) return false;
        }
    }
    else if (daia>daib) return true;
    return false;
}
bool operator>(mavasolan const &a,mavasolan const &b){
    if(a.solanxuathien<b.solanxuathien) return true;
    if(a.solanxuathien==b.solanxuathien)
        if(cmp2str(a.code,b.code)) return true;
    return false;
}
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

void heap(vector<string> &arr, int N)
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
void heapify(vector<mavasolan> &arr, int N, int i)
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
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap

void heap(vector<mavasolan> &arr, int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main(){
    vector<string> dayma;
    string temp;
    int n;cin>>n;
    cin.ignore();
    for(int i =0;i<n;i++){
        getline(cin,temp);
        dayma.push_back(temp);
    }
    heap(dayma,n);
    vector<mavasolan> daymavasolan;
    mavasolan tempmavasolan;
    tempmavasolan.code=dayma[0];
    tempmavasolan.solanxuathien=1;
    daymavasolan.push_back(tempmavasolan);
    int vitri=0;
    for(int i=0;i<n-1;i++){
        if(dayma[i+1]!=dayma[i]){
            tempmavasolan.code=dayma[i+1];
            tempmavasolan.solanxuathien=1;
            daymavasolan.push_back(tempmavasolan);
            vitri++;
        }
        else daymavasolan[vitri].solanxuathien++;
    }
    vitri++;
    heap(daymavasolan,vitri);
    for(int i=0;i<vitri;i++) cout<<daymavasolan[i].code<<" "<<daymavasolan[i].solanxuathien<<"\n";
}