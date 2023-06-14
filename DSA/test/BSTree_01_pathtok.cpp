/*Tạo một cây nhị phân tìm kiếm T lưu trữ các số nguyên (giá trị số nguyên < 1000, cây T có thể rỗng). 
Nhập giá trị của 1 node X và xuất ra tất cả các node tổ tiên của X.
Ví dụ:

                9
              /   \
            6      16
          /  \    /  \
         2    7  12   25
       /   \    /    /
      1     4  11   20

Nhập X=1. Xuất ra các node tổ tiên: 9, 6, 2
INPUT

- Dãy số nguyên gồm: Số nguyên đầu tiên là gốc của cây và các số nguyên còn lại sẽ được lần lượt thêm vào cây theo thứ tự nhập. Kết thúc khi gặp -1.

- Số nguyên cuối cùng là X*/

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -
TNODE* insertNode(TNODE* tree, int data) {
	if (!tree) {
		TNODE* temp = new TNODE;
		temp->key = data;
		temp->pLeft = NULL;
		temp->pRight = NULL;
		return temp;
	} 
	else if (data > tree->key)
		tree->pRight = insertNode(tree->pRight, data);
	else if (data < tree->key)
		tree->pLeft = insertNode(tree->pLeft, data);
	return tree;
}

void CreateTree(TREE& T){
	T=NULL;
	int tempinsert;
	cin>>tempinsert;
	while(tempinsert!=-1){
		T=insertNode(T,tempinsert);
		cin>>tempinsert;
	}
}
bool searchNode(TREE T,int data){
	while(T){
		if(data>T->key)
			T=T->pRight;
		else if(data<T->key)
			T=T->pLeft;
		else if(data==T->key)
			return true;
	}
	return false;
}
void Function(TREE T){
	if(!T){
		cout<<"No Find";
		return;
	}
	int k;cin>>k;
	if(k==T->key){
		cout<<"Root no ancestor";
		return;
	}
	else if(searchNode(T,k)){
		while(T){
			if(k==T->key) return;
			cout<<T->key<<" ";
			if(k>T->key) T=T->pRight;
			else if(k<T->key) T=T->pLeft;
		}
	}
	cout<<"No Find";
}
int main() {
	TREE T;
	CreateTree(T);
	Function(T);
	return 0;
}

