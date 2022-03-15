#include"iostream"
#include"string"
#include"stdlib.h"
using namespace std;

struct SinhVien {
	int mssv;
	char name[100];
	char lop[10];
	char sbd[10];
	float dtb;
};
typedef struct SinhVien sinhvien;
struct node {
	sinhvien *data;
	struct  node* link;
};
typedef struct node Node;
struct list {
	Node* pHead;
	Node* pTail;
};
typedef struct list List;
void KhoiTaoList(List &l) {
	l.pHead = l.pTail = NULL;
}
void Input_ThongTin(sinhvien *sv) {
	cout << "Nhap Ten: ";fflush(stdin);
	gets(sv->name);	
	cout << "Nhap Lop: ";fflush(stdin);
	gets(sv->lop);	
	cout << "Nhap SBD: ";
	gets(sv->sbd);fflush(stdin);
	cout << "Nhap DTB: ";
	cin>>sv->dtb;fflush(stdin);
}
Node *KhoiTaoNode() {
	sinhvien* sv = new sinhvien;
	Input_ThongTin(sv);
	Node* p = new Node;
	if (p == NULL) {
		cout << "Full ram ko the tao them\n";
		return 0;
	}
	p->data = sv;
	p->link = NULL;
	return p;
}
void ThemVaoDauMotSinhVien(List &l, Node *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail= p;
	}else {
		p->link = l.pHead;
		l.pHead = p;
	}
}
void Show(List l) {
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		cout << "Ten : " << k->data->name << endl;
		cout << "Lop : " << k->data->lop << endl;
		cout << "SBD : " << k->data->sbd << endl;
		cout << "DTB : " << k->data->dtb << endl;
		cout << "==============================SV==============================\n";
	}
}
void showNode(Node *k) {
	cout << "==============================SV==============================\n";
	cout << "Ten : " << k->data->name << endl;
	cout << "Lop : " << k->data->lop << endl;
	cout << "SBD : " << k->data->sbd << endl;
	cout << "DTB : " << k->data->dtb << endl;
}
int dem(List l) {
	int dem=0;
	for (Node* k = l.pHead; k != NULL; k = k->link){
		if(k->data->dtb >= 5)
			dem++;
	}
	return dem++;
}
void ChucNang(List &l) {
	int n;
	cout << "=========Danh Sach Chuc Nang=========\n";
	cout << "1 => Nhap 1 sinh vien moi\n";
	cout << "2 => In danh sach sinh vien\n";
	cout << "3 => Dem so SV co DTB >= 5.0\n";
	cout << "0 = >Thoat chuong trinh";
	while (1){
		cout << "\nNhap chuc nang ban chon: ";
		cin >> n;
		if (n == 1){
			cout << "\nNhap thong tin 1 sinh vien moi: \n";
			Node* p = KhoiTaoNode();
			ThemVaoDauMotSinhVien(l, p);
		}if (n == 2) {
			cout << "==============================SV==============================\n";
			cout << "Danh Sach Sinh Vien: \n";
			Show(l);
		}if (n == 3) {
			cout << "\nSo SV co DTB >= 5.0 la: "<<dem(l)<<endl;
		}if (n == 0) {
			break;
		}
	}
}
int main() {
	List l;
	KhoiTaoList(l);
	ChucNang(l);
	return 0;
}
