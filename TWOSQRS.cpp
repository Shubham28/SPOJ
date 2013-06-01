#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VB vector<bool>
#define LL long long

using namespace std;

/*	Due to Fermat:
	A number N is expressible as a sum of 2 squares if and only if in the prime factorization of N,
	every prime of the form (4k+3) occurs an even number of times.

	A corollary of this fact is that every prime of the form (4k+1) can be written as the sum of two squares.	*/

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

VB chk;
void SieveFull(int N)
{
	if(N%2==0)
		--N;

	int range=(N-1)/2;
	int limit=int(sqrt(N+0.)+1e-7)/2;

	chk.assign(range,true);

	EFOR(i,1,limit){
		if(chk[i-1])
			for(int j=2*i*(i+1);j<=range;j+=(2*i+1))
				chk[j-1]=false;
	}
	return;
}

int main()
{
	int T;
	Input(T);
	SieveFull(1000001);

	while(T--){
		LL num;
		scanf("%lld",&num);
		if(num==0ll){
			printf("Yes\n");
			continue;
		}

		LL N=num;
		if(N%2==0){
			N/=2;
			while(N%2==0)
				N/=2;
		}

		LL fact=3;
		bool flag=true;
		while(N>1 && fact*fact<=N){

			if(N%fact==0){
				int	cnt=1;
				N/=fact;
				while(N%fact==0)
					N/=fact,++cnt;

				if(fact%4==3 && chk[(fact-3)/2])
					if(cnt%2==1){
						flag=false;
						break;
					}
			}
			fact+=2;
		}

		if(N!=1 && N%4==3)
			flag=false;

		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
