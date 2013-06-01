#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

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

struct postr{
	int strt,end;
	struct postr *left,*rgt;
	bool emp;
};

int all[40001][2];

bool hang(struct postr *now,int frm,int to)
{
	if(now->emp){
		now->strt=frm,now->end=to;
		now->emp=0;

		struct postr *tmp1,*tmp2;
		tmp1=new postr;
		tmp2=new postr;
		tmp1->emp=tmp2->emp=1;
		tmp1->left=tmp2->rgt=NULL;
		now->left=tmp1,now->rgt=tmp2;

		return 1;
	} else {
		int tlf=now->strt,trt=now->end;

		if(tlf<=frm && to<=trt)		return 0;

		if(frm<tlf && trt<to)
			return hang(now->left,frm,tlf-1)|hang(now->rgt,trt+1,to);

		if(frm<tlf)		return hang(now->left,frm,min(to,tlf-1));
		if(trt<to)		return hang(now->rgt,max(frm,trt+1),to);
	}
}

int main()
{
	int T,N;
	Input(T);
	while(T--){

		Input(N);
		int tl,tr,mn=1000001,mx=0;
		FOR(inp,0,N){
			Input(tl),Input(tr);
			all[inp][0]=tl,all[inp][1]=tr;
			mn=(mn<tl)?mn:tl;
			mx=(mx>tr)?mx:tr;
		}

		struct postr *root=new postr;
		root->strt=mn,root->end=mx;
		root->left=root->rgt=NULL;
		root->emp=1;

		int ans=0;
		RFOR(rev,N-1,0)
			ans+=hang(root,all[rev][0],all[rev][1]);
		printf("%d\n",ans);
	}

	return 0;
}
