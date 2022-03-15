#include<iostream>

using namespace std;

class Node{
public: 
	int data;
	Node *next;
	Node(){
		data = 0;
		next = NULL;
	};
	void input() {
		cout<<"Nhap du lieu: ";
		cin>>data;
	};
	Node *pop(Node *&nodeIp) {
		if(nodeIp == NULL) {
		cout<<"Danh Sach Rong!";
		} else {
			Node *popedNode = nodeIp;
			nodeIp = nodeIp->next;
			return popedNode;
		}
	};
	void push(Node *&stack, Node *newNode) {
		Node *p = stack;
		newNode->next = stack;
		stack = newNode;
	};
	Node *Tao_Node () {
		Node *newNode = new Node();
		newNode->input();
		return newNode;
	};
	void Xoa(Node *&stack) {
		if(stack == NULL) {
			cout<<"Danh Sach Rong!";
			return;
		}
		Node *p = stack;
		stack = stack->next;
		delete p;
	}
};

void Xuat(Node *stack) {
	if(stack==NULL) {
		cout<<"Danh Sach Rong!";
	}else {
		while(stack != NULL) {
			cout<< stack->data <<" ";
			stack = stack->next;
		}	
	} 
}

void Them_K(Node *&stack) {
	int vt;
	int size = 0;

	Node *p = stack, *temp = NULL;
	while(p != NULL) {
		size++;
		p = p->next;
	}
	do{
		cout<<"Nhap vi tri can them: ";
		cin>>vt;
	}while(vt<1 || vt>size);
	
	for(int i = 0 ; i < size - vt; i++) {
		temp->push(temp, stack->pop(stack));
	}
	stack->push(stack, stack->Tao_Node());
	for(int i = 0 ; i < size - vt; i++) {
		stack->push(stack, temp->pop(temp));
	}
}

void Xoa_K(Node *&stack) {
	int vt;
	int size = 0;
	cout<<endl;
	Node *p = stack, *temp = NULL;
	while(p != NULL) {
		size++;
		p = p->next;
	}
	do{
		cout<<"Nhap vi tri can xoa: ";
		cin>>vt;
	}while(vt<1 || vt>size);

	for(int i = 0 ; i < size - vt; i++) {
		temp->push(temp, stack->pop(stack));
	}
	stack->Xoa(stack);
	for(int i = 0 ; i < size - vt; i++) {
		stack->push(stack, temp->pop(temp));
	}
}

void Xoa_Duoi(Node *&stack) {
	Node *p = stack;
	while(p->next->next != NULL) {
		p = p->next;
	}
	delete p->next->next;
	p->next = NULL;
}
		
void Them_Duoi(Node *&stack) {
	Node *p = stack;
	while(p->next->next != NULL) {
		p = p->next;
	}
	p->next = stack->Tao_Node();
}

void Nhiphan() {
	int n;
	cout<<endl;
	do{
		cout<<"Nhap so can doi: ";
		cin>>n;
	}while(n<1);
	
	Node *newStack = NULL;
	while(n != 0) {
		int data = n % 2;
		Node *newNode = new Node();
		newNode->data = data;
		newStack->push(newStack, newNode);
		n /= 2;
	};
	while(newStack != NULL) {
		cout<<newStack->data<<" ";
		newStack = newStack->next;
	}
}
	 
int main(){
	Node *stack = NULL;
	int n;
	do{	
		cout<<"Nhap so luong phan tu: ";
		cin>>n;
	}while(n<1);
	for(int i = 0; i < n; i++) {
		stack->push(stack, stack->Tao_Node());
}
//--1
	cout<<endl;
	cout<<"---Them phan tu tai vi tri K---"<<endl;
	Them_K(stack);
	Xuat(stack);
	cout<<endl;
//////--2
	cout<<endl;
	cout<<"---Xoa phan tu tai vi tri K---";
	Xoa_K(stack);
	Xuat(stack);
	cout<<endl;
////--3
	cout<<endl;
	cout<<"---Chuyen doi 1 so tu nhien thanh so Nhi Phan---";
	Nhiphan();
	cout<<endl;
//--4
	cout<<endl;
	cout<<"---Xoa Duoi---"<<endl;
	Xoa_Duoi(stack);
	cout<<"Danh Sach Sau Khi Xoa Duoi: ";
	Xuat(stack);
	cout<<endl;
//--5
	cout<<endl;
	cout<<"---Them Duoi---"<<endl;
	Them_Duoi(stack);
	cout<<"Danh Sach Sau Khi Them Duoi: ";
	Xuat(stack);
	
return 0;
}
