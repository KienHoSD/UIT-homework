/*Sắp xếp mảng một chiều các số nguyên giảm dần bằng phương pháp Selection sort.

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng -1 và không thêm số -1 vào danh sách A. 

Hãy cho biết 2 giá trị hoán vị ở tại mỗi bước i trong quá trình sắp xếp.
INPUT 

    Nhập giá trị các phần tử của danh sách A. 

OUTPUT 

    Xuất ra 2 giá trị hoán vị tại mỗi bước i trong quá trình sắp xếp theo mô tả.
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
void Sort(vector<int>& A){
	if(A.empty()) return;
	int pivot=0;
	for(int i=0;i<A.size()-1;i++){
		int max=A[i];
		for(int j=i;j<A.size();j++)
			if(A[j]>=max){
				pivot = j;
				max = A[j];
			}
		cout<<"i="<<i<<": swap ("<<A[i]<<"-"<<A[pivot]<<")\n";
		swap(A[i],A[pivot]);
	}
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
