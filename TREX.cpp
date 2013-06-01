#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int T;
	Input(T);
	while(T--){
		int N,D,C;
		Input(N),Input(D),Input(C);

		int ans=0;
		for(;D>0 && N>D && C>1;D--){

			if(N<=C){
				ans=max(0,N-D);
				break;
			}

			int rem=N%C;
			int trp=N/C;

			if(rem<=2)
				N-=(rem+2*trp-1);
			else {										//	Optimization possible by jumping many steps instead of 1
				++trp;
				N-=(2*trp-1);
			}
		}
		if(D==0)
			ans=N;

		printf("%d\n",ans);
	}

	return 0;
}
