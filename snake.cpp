#include<iostream>
int width=30;
int height=15;
using namespace std;
void block(){
	int i,j;
	for (i=0;i<width+1;i++)
		cout<<"#";
	cout<<endl;
	for (i=0;i<height;i++){
		for (j=0;j<width;j++){
			if (j==0)
				cout<<"#";
			else
				cout<<" ";
			if (j==width-1)
				cout<<"#";
		}
		cout<<endl;
	}
	for (i=0;i<width+1;i++)
		cout<<"#";
	cout<<endl;
}
int main (){
	block();
	return 0;
}
