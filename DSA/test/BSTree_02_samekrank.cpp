/*Tạo một cây nhị phân tìm kiếm T lưu trữ các số nguyên (giá trị số nguyên < 1000, cây T có thể rỗng). 
Nhập vào một số nguyên k và  xuất ra tất cả các node ở cùng mức k.
Ví dụ:

                9
              /   \
            6      16
          /  \    /  \
         2    7  12   25
       /   \    /    /
      1     4  11   20

Nhập k=0. Xuất ra các node ở mức 0 gồm: 9
INPUT

- Dãy số nguyên gồm: Số nguyên đầu tiên là gốc của cây và các số nguyên còn lại sẽ được lần lượt thêm vào cây theo thứ tự nhập. Kết thúc khi gặp -1.

- Số nguyên cuối cùng là mức k
OUTPUT

- Nếu k>=0 && k<=chiều cao của cây --> xuất tất cả các node ở cùng mức k

- Nếu k<0 hoặc k>chiều cao của cây --> xuất "Khong co node o muc k"

- Nếu cây rỗng --> xuất "Empty Tree"*/

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
void in_node_bac_k(TNODE* node,int k){
    if(!node)
        return;
    if(k==0) cout<<node->key<<" ";
    else{
        in_node_bac_k(node->pLeft,k-1);
        in_node_bac_k(node->pRight,k-1);
    }
}
int Height(TNODE* T) {
	if (!T) return -1;
	int a = Height(T->pLeft);
	int b = Height(T->pRight);
	return (a > b ? a : b) + 1;
}
void Function(TREE T){
	if(!T){
		cout<<"Empty Tree";
		return;
	}
	int k; cin>>k;
	if(k>Height(T)||k<0) cout<<"Khong co node o muc "<<k;
	else cout<<"Xuat cac node o muc "<<k<<":\n"; in_node_bac_k(T,k);
}	

int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}

