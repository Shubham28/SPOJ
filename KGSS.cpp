#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SORT(A) sort( A.begin(),A.end() )
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int N,fr,to,flp,val;
int ar[100005];
int P[(1<<18)+5][2];

void init(int ind,int st,int end)
{
	if(st==end)		P[ind][0]=ar[st],P[ind][1]=-1;
	else {
		int nxt=ind<<1,mid=(st+end)>>1;
		init(nxt,st,mid);
		init(nxt+1,mid+1,end);

		int tmp[4];
		tmp[0]=P[nxt][0],tmp[1]=P[nxt][1],tmp[2]=P[nxt+1][0],tmp[3]=P[nxt+1][1];
		sort(tmp,tmp+4,greater<int>());
		P[ind][0]=tmp[0],P[ind][1]=tmp[1];
	}
	return;
}

void query(int ind,int st,int end,int bst[2])
{
	if(fr>end || to<st)		return;
	if(st>=fr && end<=to){
		memcpy(bst,P[ind],sizeof(P[ind]));
		return;
	}

	int nxt=ind<<1,mid=(st+end)>>1;
	int tmp1[2],tmp2[2];
	MEM(tmp1,-1);	MEM(tmp2,-1);
	query(nxt,st,mid,tmp1);
	query(nxt+1,mid+1,end,tmp2);

	int inc[4];
	inc[0]=tmp1[0],inc[1]=tmp1[1],inc[2]=tmp2[0],inc[3]=tmp2[1];
	sort(inc,inc+4,greater<int>());

	bst[0]=inc[0],bst[1]=inc[1];
	return;
}

void update(int ind,int st,int end)
{
	if(flp>end || flp<st)		return;

	if(st==end && st==flp){
		P[ind][0]=val;
		return;
	}

	int nxt=ind<<1;
	int mid=(st+end)>>1;
	update(nxt,st,mid);
	update(nxt+1,mid+1,end);

	int tmp[4];
	tmp[0]=P[nxt][0],tmp[1]=P[nxt][1],tmp[2]=P[nxt+1][0],tmp[3]=P[nxt+1][1];
	sort(tmp,tmp+4,greater<int>());
	P[ind][0]=tmp[0],P[ind][1]=tmp[1];

	return;
}


int main()
{
	int N;
	scanf("%d",&N);
	FOR(i,0,N)
		scanf("%d",&ar[i]);

	init(1,0,N-1);

	int Q;
	scanf("%d",&Q);

	int tmp[2],chc[2];
	for(int in=0;in<Q;in++){
		char ch;
		scanf("%s",chc);
		ch=chc[0];

		if(ch=='Q'){
			scanf("%d%d",&fr,&to);
			fr--,to--;
			query(1,0,N-1,tmp);
			printf("%d\n",tmp[0]+tmp[1]);
		} else if(ch=='U'){
			scanf("%d%d",&flp,&val);
			flp--;
			update(1,0,N-1);
		}
	}

	return 0;
}

