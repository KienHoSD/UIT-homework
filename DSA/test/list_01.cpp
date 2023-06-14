/*Viết chương trình quản lý các ĐIỂM trong mặt phẳng Oxy bằng danh sách liên kết đơn. Biết rằng hoành độ ox và tung độ oy của một điểm là số nguyên.

Hãy sắp xếp danh sách điểm theo thứ tự tăng dần hoành độ, nếu 2 điểm có hoành độ bằng nhau thì sắp theo thứ tự tăng dần tung độ.
INPUT

Dãy các số nguyên trong đó: (Giả sử luôn thỏa điều kiện nhập)

    Số nguyên đầu tiên là: số lượng điểm trong danh sách.
    n dòng tiếp theo, mỗi dòng chứ 02 số nguyên lần lượt là tung độ và hoành độ của một điểm trong danh sách.

OUTPUT

Xuất ra danh sách các điểm đã được sắp xếp theo hoành độ và tung độ.*/
#include <iostream>
#include <string.h>
using namespace std;

struct point {
    int x, y;
};

struct node {
	point info;
	node* next;
};

struct List {
	node* head;
	node* tail;
};
//###INSERT CODE HERE -
#include <algorithm>
#include <vector>
void insert_node(List& L, point data){
	if(!L.head){
		node* temp = new node;
		temp->info=data;
		temp->next=nullptr;
		L.head=temp;
		L.tail=temp;
		return;
	}
	node* prev = L.head;
	while(prev->next)
		prev=prev->next;
	node* newnode = new node;
	newnode->info = data;
	prev->next = newnode;
}

bool x_y_ascending(point a, point b){
	if(a.x<b.x) return true;
	if(a.x==b.x)
		if(a.y<b.y) return true;
	return false;
}
void sort_point(vector<point>& arrayPoint){
	sort(arrayPoint.begin(),arrayPoint.end(),x_y_ascending);
}
void CreateEmptyList(List& L){
	L.head=NULL;
	L.tail=NULL;
}
void CreateList(List L){
	int n,x,y;cin>>n;
	vector<point> arrayPoint;
	point temp_point;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		temp_point.x=x; temp_point.y=y;
		arrayPoint.push_back(temp_point);
	}
	sort_point(arrayPoint);
	for(int i=0;i<n;i++){
		insert_node(L,arrayPoint[i]);
	}
}
void PrintList(const List& L){
	node* temp = L.head;
	while(temp){
		cout<<"("<<temp->info.x<<","<<temp->info.y<<")\n";
		temp=temp->next;
	}
}


int main() {
    List L;
	CreateEmptyList(L);
	CreateList(L);
	PrintList(L);
    return 0;
}