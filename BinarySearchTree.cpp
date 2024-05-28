#include "iostream"
using namespace std;

//Tạo struct node
struct node 
{
	int data;
	node *left;
	node *right;	
};
// Tạo cây rỗng
void TaoCay(node *&t){
	t = NULL;
}
//Hàm thêm node vào cây
void ThemNode(node *&t, int x){
	if(t == NULL){
		node *p = new node;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		t = p;
	} else {
		if(x < t->data){
			ThemNode(t->left,x);
		} else if(x > t->data){
			ThemNode(t->right,x);
		}
	}
}
//Duyệt node trong cây theo Node-Left-Right
void DuyetNLR(node *t){
	if(t != NULL){
		cout << t->data << " ";
		DuyetNLR(t->left);
		DuyetNLR(t->right);
	}
}
//Duyệt node trong cây theo Node-Right-Left
void DuyetNRL(node *t){
	if(t != NULL){
		cout << t->data << " ";
		DuyetNRL(t->right);
		DuyetNRL(t->left);
	}
}
//Duyệt node trong cây theo Left-Node-Right
void DuyetLNR(node *t){
	if(t != NULL){
		DuyetLNR(t->left);
		cout << t->data << " ";
		DuyetLNR(t->right);
	}
}
//Duyệt node trong cây theo Right-Node-Left
void DuyetRNL(node *t){
	if(t != NULL){
		DuyetRNL(t->right);
		cout << t->data << " ";
		DuyetRNL(t->left);
	}
}
//Duyệt node trong cây theo Left-Right-Node
void DuyetLRN(node *t){
	if(t!= NULL){
		DuyetLRN(t->left);
		DuyetLRN(t->right);
		cout << t->data << " ";
	}
}
//Duyệt node trong cây theo Right-Left-Node
void DuyetRLN(node *t){
	if(t != nullptr){
		DuyetRLN(t->right);
		DuyetRLN(t->left);
		cout << t->data << " ";
	}
}

int main(){
	node *t;
	TaoCay(t);
	ThemNode(t,5);
	ThemNode(t,1);
	ThemNode(t,-2);
	ThemNode(t,2);
	ThemNode(t,6);
	ThemNode(t,7);
	cout << "NLR: ";
	DuyetNLR(t);
	cout << "\nNRL: ";
	DuyetNRL(t);
	cout << "\nLNR: ";
	DuyetLNR(t);
	cout << "\nRNL: ";
	DuyetRNL(t);
	cout << "\nLRN: ";
	DuyetLRN(t);
	cout << "\nRLN: ";
	DuyetRLN(t);
	return 0;
}
