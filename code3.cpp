#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int _;
	cin >> _;
	int copy = _;
	int digit;
	int enumerate=0;
	int num=0;
	while(copy!=0){
		digit = copy%10;
		if (digit==0){digit=5;}
		num = num + (digit * pow(10, enumerate));

		enumerate++;
		copy = copy/10;
	}
	if(_==0){cout<<5; return 0;}
	cout << "\nnum : "<<num;
	return 0;
}