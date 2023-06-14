/*Sắp xếp mảng một chiều các số nguyên giảm dần bằng phương pháp insertion sort. 

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng -1 và không thêm số -1 vào danh sách A. 

Xuất ra màn hình giá trị pos và e ở mỗi bước i trong quá trình sắp xếp. Trong đó:

- pos: là giá trị cần chèn

- e: vị trí cần chèn
INPUT 

    Nhập giá trị các phần tử của danh sách A. 

OUTPUT 

    Xuất ra giá trị pos và e ở mỗi bước i trong quá trình sắp xếp giảm dần
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
void Swap(vector<int>& A,int i,int j){
	for(int e=i;e>j;e--)
		swap(A[e],A[e-1]);
}
void Sort(vector<int> A){
	int j=0;
	for(int i=1;i<A.size();i++){
		for(int j=0;j<=i;j++){
			if(A[i]>=A[j]){
				cout<<"i="<<i<<": pos="<<A[i]<<" e="<<j<<'\n';
				Swap(A,i,j);
				break;
			}
		}
	}
}
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
