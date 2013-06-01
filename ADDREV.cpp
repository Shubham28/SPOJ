#include <iostream>
#include <algorithm>

using namespace std;

int reversed(int inp)
{
	char buff[20];
	sprintf(buff,"%d",inp);
	string tmp(buff);
	reverse(tmp.begin(),tmp.end());

	return atoi(tmp.c_str());
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--){
		int num1,num2;
		scanf("%d%d",&num1,&num2);

		printf("%d\n",reversed(reversed(num1)+reversed(num2)));
	}

	return 0;
}
