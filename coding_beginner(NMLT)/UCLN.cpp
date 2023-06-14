#define MAX 100
#include <iostream>
using namespace std;

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap a[" << i << "] = ";
		cin >> a[i];
	}
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "   ";
}
int Min(int a[], int n) // tìm ra phần tử Min (nhỏ nhất) trong mảng
{
	int Min = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < Min)
			Min = a[i];
	return Min; // trả về phần tử nhỏ nhất trong mảng là Min
}
bool KiemTraChiaHet(int a[], int n, int x) // kiểm tra xem tất cả các phần tử trong mảng có chia hết cho phần tử X hay không
{
	for (int i = 0; i < n; i++)
		if (a[i] % x != 0)
			return false;
	return true; // tất cả các phần tử trong mảng chia hết cho phần tử X
}
int UCLN(int a[], int n)
{
	int b[MAX], m = 0, phantu = 0; // tạo 1 mảng b khác.
	int Minimum = Min(a, n); // 12
	if (KiemTraChiaHet(a, n, Minimum)) // nếu trong mảng có 1 số mà tất cả các phần tử đều chia hết cho số đó thì số đó là UCLN
		return Minimum;
	else // Nếu không thì chúng ta phân tích các trường hợp:
	{
		for (int i = 1; i <= Minimum / 2; i++) // Lưu tất cả các ước của số Min trừ chính nó vào mảng b
		{
			if (Minimum % i == 0)
			{
				b[phantu++] = i;
				m++;
			}
		}
		for (int i = m - 1; i >= 0; i--) // xét từng ước của Min (trừ chính nó)
		{
			bool Check = true;
			for (int j = 0; j < n; j++) // xét các số trong mảng, nếu số nào không chia hết cho b[i] thì false và không xét nữa
			{
				if (a[j] % b[i] != 0)
				{
					Check = false;
					break;
				}
			}
			if (Check == true) //chạy xong vòng lặp trên mà Check vẫn true, nghĩa là tất cả các số trong mảng đều chia hết cho b[i]
				return b[i]; // b[i] chính là số phải tìm
		}
	}
}
int main()
{
	int a[MAX];
	int n;
	do
	{
		cout << "\nNhap so luong phan tu: ";
		cin >> n;
		if (n < 0 || n > MAX)
			cout << "\nSo luong phan tu khong hop le";
	} while (n < 0 || n > MAX);
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\nUCLN cua cac phan tu trong mang: " << UCLN(a, n) << endl;
	return 0;
}
