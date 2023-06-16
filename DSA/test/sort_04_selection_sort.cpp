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
	for(int i=0;i<A.size()-1;i++){
		int max=i;
		for(int j=i+1;j<A.size();j++)
			if(A[j]>A[max])
				max = j;
		cout<<"i="<<i<<": swap ("<<A[i]<<"-"<<A[max]<<")\n";
		swap(A[i],A[max]);
	}
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
