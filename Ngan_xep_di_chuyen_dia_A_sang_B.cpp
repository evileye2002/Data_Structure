#include <iostream>
using namespace std;
void move(int n,char A,char B,char C){
    if(n==1){
    	cout<<A<<" ---> "<<C<<"\n";
	}else{        
        move(n - 1, A, C, B);
        cout<<A<<" ---> "<<C<<"\n";
        move(n - 1, B, A, C);
    }
 }
int main(){
	int n;
	cout<<endl<<"Nhap vao so dia N: ";cin>>n;
	cout<<"Thu tu dich chuyen cac vi tri A B C: \n";
	move(n, 'A', 'B', 'C');
}
