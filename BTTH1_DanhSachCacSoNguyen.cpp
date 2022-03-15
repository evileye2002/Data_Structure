#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList *node;
 
node TaoNode(int value){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->data = value;
    return temp;
}
 
node ThemDuoi(node head, int value){
    node temp,p;
    temp = TaoNode(value);
    if(head == NULL){
        head = temp;
    }else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }return head;
}

node ThemDau(node head, int value){
    node temp = TaoNode(value);
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }return head;
}
 
node ThemViTriBatKi(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = ThemDau(head, value);
    }else{
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }if(k != position){
            head = ThemDuoi(head, value);
        }else{
            node temp = TaoNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }return head;
}
 
node XoaDau(node head){
    if(head == NULL){
        printf("\nKhong co gi de xoa!");
    }else{
        head = head->next;
    }return head;
}
 
node XoaDuoi(node head){
    if (head == NULL || head->next == NULL){
         return XoaDau(head);
    }
	node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next;
    return head;
}
 
node XoaViTriBatKi(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = XoaDau(head);
    }else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
        if(k != position){
            head = XoaDuoi(head);
        }else{
            p->next = p->next->next;
        }
    }return head;
}

int LayViTriBatKi(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }return p->data;
}
 
int TimKiem(node head, int value){
    int position = 0;
    for(node p = head; p != NULL; p = p->next){
        if(p->data == value){
            return position;
        }
        ++position;
    }
    return -1;
}
 
node XoaTatCa(node head, int value){
    int position = TimKiem(head, value);
    while(position != -1){
        XoaViTriBatKi(head, position);
        position = TimKiem(head, value);
    }
    return head;
}
 
void DuyetDS(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}
 
node KhoiTaoHead(){
    node head;
    head = NULL;
    return head;
}
 
int LengthAM(node head){
    int length = 0;
    for(node p = head; p ; p = p->next){
    	if(p->data<0){
        	++length;
    	}
    }
    return length;
}
int LengthDUONG(node head){
    int length = 0;
    for(node p = head; p ; p = p->next){
    	if(p->data>0){
        	++length;
    	}
    }
    return length;
}
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
int Tong(node head){
	int tong=0;
	for(node p = head; p ; p = p->next){
		tong+=p->data;
	}
	return tong;
}
node Nhap(){
    node head = KhoiTaoHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value);
        head = ThemDuoi(head, value);
    }
    return head;
}

int main(){
	int x;
    printf("\n===Tao 1 danh sach lien ket===");
    node head = Nhap();
    DuyetDS(head);
//---9---
	printf("\n===TBC cac phan tu===");
	int tong=Tong(head);
	int r=Length(head);
	float tbc=(tong/r);
	printf("\n%0.2f",tbc);//em ko hieu tai sao no ko ra ket qua dung
	printf("\n%d",tong);
	printf("\n%d",r);
//---6---
	printf("\n===Dem phan tu am tron DSLK===");
	int L = LengthAM(head);
	printf("\nCo %d phan tu am trong DSLK!",L);
	
	printf("\n===Dem phan tu duong tron DSLK===");
	int O = LengthDUONG(head);
	printf("\nCo %d phan tu Duong trong DSLK!",O);
//---4---
    printf("\n===Them 1 phan tu vao dau DSLK===");
    head = ThemDau(head, 55);
    DuyetDS(head);
//---5---
    printf("\n===Them 1 phan tu A vao vi tri bat ki K trong DSLK===");
    int A,K;
	printf("\nNhap A: ");
    scanf("%d",&A);
    printf("\nNhap vi tri K: ");
    scanf("%d",&K);
    head = ThemViTriBatKi(head, A, K);
    DuyetDS(head);
//---7---  
    printf("\n===Xoa 1 phan tu o cuoi DSLK===");
    head = XoaDuoi(head);
    DuyetDS(head);
//---8---
    printf("\n===Xoa 1 phan tu x tai vi tri bat ki khoi DSLK===");
    printf("\nNhap x: ");
    scanf("%d",&x);
    int index = TimKiem(head, x);
    head = XoaViTriBatKi(head, index);
    DuyetDS(head);
//    printf("\n===Tim kiem 1 phan tu trong DSLK===");
//    int in = TimKiem(head, 2);
//    printf("\nTim thay tai chi so %d", in);
}
