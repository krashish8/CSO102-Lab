
#include<stdio.h>
#include<math.h>\
int main(){
	int amp=5,star=10,k;
	int i,j;
	cin>>amp>>star;

	for(int i=0;i<star;i++){
		k=(amp+10)+(amp*sin(6.28*i/(star-1)));
		for(int j=1;j<k;j++)
		cout<<" ";
		cout<<"*\n";
	}

}
