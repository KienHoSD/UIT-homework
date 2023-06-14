/*Sắp xếp danh sách A tăng dần bằng phương pháp QuickSort. 

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng -1 và không thêm số -1 vào danh sách A. 

Liệt kê các đoạn phân hoạch trong quá trình sắp xếp tăng dần bằng QuickSort

INPUT

    Nhập giá trị các phần tử của danh sách A.  

OUTPUT

    Xuất các đoạn phân hoạch trong quá trình sắp xếp theo mô tả.
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

//###INSERT CODE HERE -
void quick_sort_ascending(vector<int> &a, int left, int right, int &dem){
    int pivot=a[(left+right)/2];
    int i=left, j=right;
    dem++;
     cout<<"["<<left<<" - "<<right<<"]: ";
    while(i<j){
        while(a[i]< pivot) i++;
        while(a[j]> pivot) j--;
        if(i<=j) {
            swap(a[i], a[j]);
            i++;j--;
        }
    }
    for (int i = left; i <= right; i++)
        cout << a[i] << "\t";
    cout<<endl;
    if(left<j) quick_sort_ascending(a, left, j,dem);
    if(i<right) quick_sort_ascending(a, i, right,dem);
}


void Sort(vector<int> &A)
{
    int dem=0;
	quick_sort_ascending(A,0,A.size()-1,dem);
}
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
