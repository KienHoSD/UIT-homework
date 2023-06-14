/*Tạo một cây nhị phân tìm kiếm T lưu trữ các số nguyên (giá trị số nguyên < 1000, cây T có thể rỗng). 
Nhập giá trị 1 node X. Kiểm tra X có trên cây hay không? Nếu tìm thấy X và X là node có 2 con thì tìm node có giá trị nhỏ nhất nằm ở nhánh cây con bên phải của X (min_right)
Ví dụ:

                9
              /   \
            6      16
          /  \    /  \
         2    7  12   25
       /   \    /    /
      1     4  11   20

Nhập X=9. Xuất ra giá trị min_right = 11
INPUT

- Dãy số nguyên gồm: Số nguyên đầu tiên là gốc của cây và các số nguyên còn lại sẽ được lần lượt thêm vào cây theo thứ tự nhập. Kết thúc khi gặp -1.

- Số nguyên cuối cùng là X
OUTPUT

- Nếu node X không có trên cây --> xuất "No Find"

- Nếu tìm thấy node X nhưng X không phải node 2 con --> xuất "No Node 2"

- Nếu tìm thấy node X và X là node 2 con --> xuất giá trị min_right*/

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
TNODE* searchNode(TNODE* T,int data){
	while(T){
		if(data>T->key)
			T=T->pRight;
		else if(data<T->key)
			T=T->pLeft;
		else if(data==T->key)
			return T;
	}
	return T;
}
void Function(TNODE* T){
	int k;cin>>k;
	TNODE* found = searchNode(T,k);
	if(!found){
		cout<<"No Find";
		return;
	}
	if((found->pLeft==NULL&&found->pRight!=NULL)||(found->pLeft!=NULL&&found->pRight==NULL)||(found->pLeft==NULL&&found->pRight==NULL)){
		cout<<"No Node 2";
		return;
	}	
	found=found->pRight;
	while(found->pLeft)
		found=found->pLeft;
	cout<<found->key;
}

int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}

