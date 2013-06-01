#include <iostream>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

int main()
{
	int T;
	char inp[100001];

/*	sum[] is the number of distinct subsequences ending with a character
	ret is the number of distinct subsequences till the index
*/

	LL sum[26],MOD=1000000007ll,ret;

	scanf("%d",&T);
	while(T--){
		scanf("%s",inp);

		memset(sum,0,sizeof(sum));
		LL tmp;
		int ind=inp[0]-'A';
		sum[ind]=1,ret=2;

		int len=strlen(inp);
		FOR(pos,1,len){
			ind=inp[pos]-'A';

//			Removes all subsequences ending with ('A'+ind)
			tmp=(ret-sum[ind]+MOD)%MOD;

//			Adds character ('A'+ind) to all the subsequences till now
			ret=(ret+tmp)%MOD;


			sum[ind]=(sum[ind]+tmp)%MOD;
		}
		printf("%lld\n",ret);
	}

	return 0;
}
