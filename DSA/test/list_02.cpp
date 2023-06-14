/*Viết chương trình quản lý THỜI GIAN bằng danh sách liên kết đơn. Biết rằng mỗi một thời gian sẽ chứa thông tin giờ - phút - giây

Trong đó, thời gian sẽ được tối giản theo qui ước 1 giờ = 60 phút, 1 phút = 60 giây, và giờ sẽ không vượt quá 24h

VD: 24h 70p 70s --> 1h 11p 10s
INPUT

Dãy các số nguyên trong đó: (Giả sử luôn thỏa điều kiện nhập)

    Số nguyên đầu tiên n là: số lượng thời gian trong danh sách
    n dòng tiếp theo, mỗi dòng chứ 03 số nguyên lần lượt là giờ - phút - giây của một thời gian trong danh sách

OUTPUT

Xuất ra tất cả thời gian trong danh sách đã được tối giản theo qui ước trên.*/
#include <iostream>
using namespace std;
struct TIME{
    int gio,phut,giay;
};
 
struct node {
	TIME info;
	node* next;
};

struct List{
	node* head;
	node* tail;
};

//###INSERT CODE HERE -
#include <algorithm>
#include <vector>
void insert_node(List& L, TIME data){
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
void CreateList(List& L){
	int n,g,p,s;cin>>n;
	vector<TIME> arrayTime;
	TIME temp_time;
	for(int i=0;i<n;i++){
		cin>>g>>p>>s;
        temp_time.giay=s%60;
        temp_time.phut=(p+s/60)%60;
        temp_time.gio=(g+(p+s/60)/60)%24;
		arrayTime.push_back(temp_time);
	}
	reverse(arrayTime.begin(),arrayTime.end());
	for(int i=0;i<n;i++){
		insert_node(L,arrayTime[i]);
	}
}
void PrintList(const List& L){
	node* temp = L.head;
	while(temp){
		cout<<temp->info.gio<<"h"<<temp->info.phut<<"p"<<temp->info.giay<<"s\n";
		temp=temp->next;
	}
}
int main() {
    List L;
    CreateList(L);
    PrintList(L);
    return 0;
}
