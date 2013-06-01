#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())

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

char data[30005];
int N,Q,flp;
int uopn[(1<<16)+5];
int ucls[(1<<16)+5];

void init(int ind,int st,int end)
{
	if(st==end){
		if(data[st]=='(')	uopn[ind]=1,ucls[ind]=0;
		else		uopn[ind]=0,ucls[ind]=1;
	} else {
		int nxt=ind<<1,mid=(st+end)>>1;
		init(nxt,st,mid);
		init(nxt+1,mid+1,end);

		uopn[ind]=uopn[nxt+1];
		ucls[ind]=ucls[nxt];
		if(uopn[nxt]>=ucls[nxt+1])
			uopn[ind]+=(uopn[nxt]-ucls[nxt+1]);
		else
			ucls[ind]+=(ucls[nxt+1]-uopn[nxt]);
	}
	return;
}

void update(int ind,int st,int end)
{
	if(flp>end || flp<st)		return;

	if(st==end && st==flp){
		swap(uopn[ind],ucls[ind]);
		return;
	}

	int nxt=ind<<1,mid=(st+end)>>1;

	update(nxt,st,mid);
	update(nxt+1,mid+1,end);

	uopn[ind]=uopn[nxt+1];
	ucls[ind]=ucls[nxt];
	if(uopn[nxt]>=ucls[nxt+1])
		uopn[ind]+=(uopn[nxt]-ucls[nxt+1]);
	else
		ucls[ind]+=(ucls[nxt+1]-uopn[nxt]);

	return;
}

int main()
{
	int N;
	EFOR(T,1,10){
		Input(N);
		scanf("%s",data);
		printf("Test %d:\n",T);

		init(1,0,N-1);

		Input(Q);
		FOR(ch,0,Q){
			Input(flp);

			if(flp==0)
				printf((uopn[1]==0 && ucls[1]==0)?"YES\n":"NO\n");
			else {
				flp--;
				update(1,0,N-1);
			}
		}
	}

	return 0;
}
