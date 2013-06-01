#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
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

/*	The Farey sequence of order N is the sequence of completely reduced fractions between 0 and 1 which,
	when in lowest terms, have denominators less than or equal to N, arranged in order of increasing size.

	Each new term in a Farey sequence expansion is the mediant of its neighbours.

	It computes each successive entry in terms of the previous 2 entries using the mediant property.
	If A/B , C/D are the 2 given entries, & P/Q is the unknown next entry, then C/D = (A+P) / (B+Q).
	C/D is in lowest terms so there is an integer K such that KC = A+P , KD = B+Q, giving P = KC-A , Q = KD-B.

	The value of K must give a value of P/Q which is as close as possible to C/D, which implies that
	K must be as large as possible subject to KD-B <= N, so K is the greatest integer <= (N+B)/D
*/

int main()
{
	pair<short,short>frac[12500000];
	int T;

	Input(T);
	while(T--){
		int N,M;
		Input(N),Input(M);

		if(N==1){
			FOR(inp,0,M){
				int tmp;
				Input(tmp);
				if(tmp==1)
					printf("0/1\n");
				else if(tmp==2)
					printf("1/1\n");
			}
			continue;
		}

		int len=0;
		frac[len++]=make_pair(0,1);

		int A,B,C,D,K;
		A=0,B=1,C=1,D=N;
		while(C<N){
			K=int((N+B)/D);
			int tmpa=A,tmpb=B;
			A=C,B=D;
			C=K*C-tmpa,D=K*D-tmpb;

			frac[len++]=make_pair(short(A),short(B));
		}

		FOR(inp,0,M){
			int tmp;
			Input(tmp);
			printf("%hd/%hd\n",frac[tmp-1].first,frac[tmp-1].second);
		}
	}

	return 0;
}
