#include "iostream"
using namespace std;

struct node 
{
	int data;
	node *left;
	node *right;	
};
void TaoCay(node *&t){
	t = NULL;
}
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
void DuyetNLR(node *t){
	if(t != NULL){
		cout << t->data << " ";
		DuyetNLR(t->left);
		DuyetNLR(t->right);
	}
}

void DuyetNRL(node *t){
	if(t != NULL){
		cout << t->data << " ";
		DuyetNRL(t->right);
		DuyetNRL(t->left);
	}
}

void DuyetLNR(node *t){
	if(t != NULL){
		DuyetLNR(t->left);
		cout << t->data << " ";
		DuyetLNR(t->right);
	}
}

void DuyetRNL(node *t){
	if(t != NULL){
		DuyetRNL(t->right);
		cout << t->data << " ";
		DuyetRNL(t->left);
	}
}

void DuyetLRN(node *t){
	if(t!= NULL){
		DuyetLRN(t->left);
		DuyetLRN(t->right);
		cout << t->data << " ";
	}
}

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