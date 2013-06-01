#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())

using namespace std;

#define MAXX 2500000
char *ipos, *opos, InpFile[MAXX], OutFile[MAXX], DIP[30];

inline int InpInt(int flag=0)
{
	while(*ipos<=32)	++ipos;

	if(flag)	return (*ipos++ - '0');

	int x=0,neg=0;
	char c;
	while(true){
		c=*ipos++;
		if(c=='-')	neg=1;
		else {
			if(c<=32)	return (neg?-x:x);
			x=(x<<1)+(x<<3)+(c-'0');
		}
	}
}

inline void Outp(int x)
{
	int y;
	int dig=0;
	while(x || !dig){
		y=x/10;
		DIP[dig++]=x-((y<<3)+(y<<1))+'0';
		x=y;
	}
	while(dig--)	*opos++=DIP[dig];
}

inline void InitFASTIO()
{
	ipos=InpFile;	opos=OutFile;
	fread(InpFile,MAXX,1,stdin);
}

inline void FlushFASTIO()
{
	fwrite(OutFile,opos-OutFile,1,stdout);
}

struct qr
{
	int val[3];
	bool typ;
};

int zero=0,one=1;

int fr,to;
int chng,idx;
struct qr data[230001];
int P[(1<<16)+1];

inline bool cmpr(struct qr fr,struct qr sc)
{
	if(fr.val[0]<sc.val[0])		return 1;
	if(fr.val[0]>sc.val[0])		return 0;
	return fr.typ;
}

int query(int ind,int st,int end)
{
	int p1,p2;
	if(st>=fr && end<=to){
		if(st==end)		return (P[ind]!=0);
		return P[ind];
	}

	int nxt=ind<<1,mid=(st+end)>>1;

	p1=(fr>mid || to<st)?-1:query(nxt,st,mid);
	p2=(fr>end || to<mid+1)?-1:query(nxt+1,mid+1,end);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;
	return p1+p2;
}

void updt(int ind,int st,int end,int &inc)
{
	if(st==end && st==idx){
		P[ind]=inc;
		return;
	}

	int nxt=ind<<1,mid=(st+end)>>1;
	if(idx<=mid)	updt(nxt,st,mid,inc);
	else			updt(nxt+1,mid+1,end,inc);

	P[ind]=P[nxt]+P[nxt+1];
	return;
}

int main()
{
	InitFASTIO();

	int T;
	T=InpInt();

	int L=0;
	FOR(ip,0,T){
		data[L].val[1]=InpInt();
		data[L].val[0]=ip;
		data[L++].typ=1;
	}

	int Q,tmp;
	Q=InpInt();
	FOR(ip,0,Q){
		tmp=InpInt();
		data[L].val[1]=tmp-1;
		tmp=InpInt();
		data[L].val[0]=tmp-1,data[L].val[2]=ip;
		data[L++].typ=0;
	}

	int last[1000005];
	sort(data,data+L,cmpr);
	MEM(P,0);	MEM(last,-1);

	int ans[Q];
	FOR(pc,0,L){
		if(data[pc].typ==1){
			chng=data[pc].val[1];

			if(last[chng]!=-1){
				idx=last[chng];
				updt(1,0,T-1,zero);
			}

			idx=data[pc].val[0];
			updt(1,0,T-1,one);
			last[chng]=idx;
		} else {
			fr=data[pc].val[1],to=data[pc].val[0];
			ans[data[pc].val[2]]=query(1,0,T-1);
		}
	}

	FOR(al,0,Q){
		Outp(ans[al]);
		*opos++='\n';
	}
	FlushFASTIO();

	return 0;
}
