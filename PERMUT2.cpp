#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int ar[100000];

int main()
{
	int N;
	Input(N);

	while(N!=0){

		bool flag=true;
		FOR(i,0,N){
			Input(ar[i]);

			if(flag && i+1>=ar[i] && ar[i]!=i+1 && ar[ar[i]-1]!=i+1){
				printf("not ambiguous\n");
				flag=false;
			}
		}
		if(flag)
			printf("ambiguous\n");

		Input(N);
	}

	return 0;
}
