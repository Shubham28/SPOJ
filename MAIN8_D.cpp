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

/*	https://www2.bc.edu/~rosen/public/CoinFlips.pdf
	http://www.math.ucdavis.edu/~gravner/MAT135B/materials/pat.pdf

	Expected number of coin tosses for "1011101"
	E(phi -> 1011101) = E(phi -> 101) + E(101 -> 1011101)
					  = E(phi -> 1) + E(1 -> 101) + E(1011101 -> 1011101)
					  = E(1 -> 1) + E(101 -> 101)

	Probability of winning in Horse Race

	E(phi -> A) = E(N) + pB*E(B -> A)
	E(phi -> B) = E(N) + pA*E(A -> B)
	pA + pB = 1
	where:		N=Number of tosses before a pattern occurs
*/

int main()
{
	int T;
	char inp[45],suf[45],pref[45];

	scanf("%d",&T);
	while(T--){
		scanf("%s",inp);
		int L=strlen(inp);
		LL ans=(1ll)<<L;

		EFOR(ln,1,L-1){
			strncpy(pref,inp,ln);			pref[ln]=0;
			strncpy(suf,inp+L-ln,ln);		suf[ln]=0;

			if(strcmp(pref,suf)==0)
				ans+=(1ll)<<ln;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
