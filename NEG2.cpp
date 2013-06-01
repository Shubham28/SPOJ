#include <iostream>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

int main()
{
	long num;
	scanf("%ld",&num);
	if(num==0){
		printf("0\n");
		return 0;
	}

	char ans[100];
	short len=0;

	while(num!=1){
		long quot=num/-2;
		if((quot*-2)>num)
			num=quot+1,ans[len]='1';
		else if((quot*-2)==num)
			num=quot,ans[len]='0';
		else
			num=quot,ans[len]='1';
		++len;
	}

	printf("1");
	RFOR(prnt,len-1,0)
		printf("%c",ans[prnt]);
	printf("\n");

	return 0;
}
