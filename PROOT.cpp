#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

//	http://zobayer.blogspot.com/2010/02/primitive-root.html

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

int P,G;

inline int binExp(LL bs,int exp)
{
	LL ret=1;
	while(exp!=0){
		if(exp&1)
			ret*=bs,ret%=P;

		bs*=bs,bs%=P;
		exp>>=1;
	}
	return ret;
}

int main()
{
	int T;
	Input(P),Input(T);
	while(P!=0 && T!=0){

		int phi=P-1,F=0;
		int fctr[40];

		if(phi%2==0){
			fctr[F++]=2;
			while(phi%2==0)
				phi/=2;
		}

		int fact=3;
		while(phi>1 && fact*fact<=phi){

			if(phi%fact==0){
				fctr[F++]=fact;
				while(phi%fact==0)
					phi/=fact;
			}
			fact+=2;
		}

		if(phi!=1)
			fctr[F++]=phi;

		phi=P-1;
		FOR(in,0,T){
			Input(G);

			bool prm=1;
			FOR(ch,0,F)
				if(binExp(G,phi/fctr[ch])==1){
					prm=0;
					break;
				}

			printf(prm?"YES\n":"NO\n");
		}

		Input(P),Input(T);
	}

	return 0;
}
