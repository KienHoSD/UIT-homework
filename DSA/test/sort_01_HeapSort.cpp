/*Sắp xếp danh sách A tăng dần bằng phương pháp HeapSort.

Hiển thị sự thay đổi của danh sách A và số lần hoán vị trong mỗi lần hiệu chỉnh.

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng -1 và không thêm số -1 vào danh sách A. 

INPUT

    Nhập giá trị các phần tử của danh sách A.  

OUTPUT

    N là số lượng phần tử trong danh sach A cần được sắp xếp ở mỗi lần hiệu chỉnh.
    Xuất ra danh sách A và số lần hoán vị ở mỗi lần hiệu chỉnh.
*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}
void Heapify(vector<int> &a, int heapSize, int i, int &dem) {
	int childLeft = i * 2 + 1;
	int childRight = i * 2 + 2;
	int max = i;
	if (childLeft<heapSize && a[max]<a[childLeft])//sort tăng chỉnh dấu a[max]<a[childLeft]
		max = childLeft;
	if (childRight<heapSize && a[max]<a[childRight])//sort tăng chỉnh dấu a[max]<a[childLeft]
		max = childRight;
	if (max != i) {
        //cout<<a[max]<<"\t"<<a[i]<<endl;
        dem++;
		swap(a[max], a[i]);
		Heapify(a, heapSize, max,dem);
	}
}
void buildHeap(vector<int> &a, int n, int &dem) {
	int heapSize = n;
	for (int i = n/2 - 1; i >= 0; i--)
		Heapify(a, heapSize, i,dem);
}
void Sort(vector<int> &a) {
    int n=a.size();
	int heapSize= n;
	int dem=0;

	cout<<"\nN="<<heapSize<<":\t";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << "\t";
    cout<<endl;

	buildHeap(a, heapSize,dem);
	cout<<"swap: "<<dem<<endl;

	for (int i = n - 1; i>0; i--) {
		swap(a[0], a[i]);
		heapSize -= 1;
        dem=0;
        cout<<"\nN="<<heapSize<<":\t";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << "\t";
        cout<<endl;

		Heapify(a, heapSize, 0,dem);

        cout<<"swap: "<<dem<<endl;
	}
}

// A utility function to print array of size n

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
		// 
		// 