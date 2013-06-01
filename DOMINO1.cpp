#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	int CC[101],CB[101],BC[101],BB[101];
	int len[4];
	MEM(len,0);

	char tmp[101];
	FOR(in,0,N){
		scanf("%s",tmp);

		if(tmp[0]=='C' && tmp[strlen(tmp)-1]=='C')
			CC[len[0]++]=strlen(tmp);

		if(tmp[0]=='C' && tmp[strlen(tmp)-1]=='B')
			CB[len[1]++]=strlen(tmp);

		if(tmp[0]=='B' && tmp[strlen(tmp)-1]=='C')
			BC[len[2]++]=strlen(tmp);

		if(tmp[0]=='B' && tmp[strlen(tmp)-1]=='B')
			BB[len[3]++]=strlen(tmp);
	}
	sort(CC,CC+len[0]);			reverse(CC,CC+len[0]);
	sort(CB,CB+len[1]);			reverse(CB,CB+len[1]);
	sort(BC,BC+len[2]);			reverse(BC,BC+len[2]);
	sort(BB,BB+len[3]);			reverse(BB,BB+len[3]);

	int lenCC=accumulate(CC,CC+len[0],0);
	int lenBB=accumulate(BB,BB+len[3],0);

	int ans=max(ans,max(lenCC,lenBB));

	if(len[1]==0 && len[2])
		ans=max(ans,lenBB+BC[0]+lenCC);

	else if(len[1] && len[2]==0)
		ans=max(ans,lenCC+CB[0]+lenBB);

	else if(len[1] && len[2]){
		int mn=min(len[1],len[2]);
		int psb=lenCC+accumulate(CB,CB+mn,0)+lenBB+accumulate(BC,BC+mn,0);

		if(len[1]>mn)		psb+=CB[mn];
		if(len[2]>mn)		psb+=BC[mn];

		ans=max(ans,psb);
	}
	printf("%d\n",ans);

	return 0;
}
