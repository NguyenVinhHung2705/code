#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void printList(node *l){
	node *p = l;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

void removeDuplicate(node *p)
{
	node *tmp = p; 							// con trỏ trỏ đến head của danh sách liên kết
	node *hold_duplicate_node = tmp->next; 	// con trỏ trỏ đến node tiếp theo
	while (hold_duplicate_node != NULL) 	// vì con trỏ hold_duplicate_node trỏ đến phần tử tiếp theo nên khi trỏ đến null 
	{										// thì không còn node để so sánh
	
		if(tmp->data == hold_duplicate_node->data) 	// nếu 2 node có giá trị bằng nhau thì thực hiện cho con trỏ next tmp trỏ đến												   
													// node kế tiếp của node mà con trỏ hold_duplicate_node đang giữ,
		{											// sau đó cho con trỏ hold_duplicate_node trỏ tới node tiếp theo 
			tmp->next = hold_duplicate_node->next;
			hold_duplicate_node = tmp->next;
		}
		else 							// nếu 2 node có giá trị khác nhau thì cho con trỏ tmp trỏ vào con trỏ hold_duplicate_node,
		{								// con trỏ hold_duplicate_node trỏ vào node tiếp theo
			tmp = hold_duplicate_node;
			hold_duplicate_node = tmp->next;		
		}		
	}
}

int main(){
	int n, x;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	cout << "Before remove duplicate node: ";
	printList(l);
	cout << '\n' << "After remove duplicate node: ";
	removeDuplicate(l);
	printList(l);
	return 0;
}
