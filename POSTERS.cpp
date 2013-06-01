#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
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

struct info{
	int loc[2];
	int ind;
};

struct info *pst[40001];
bool prsnt[40001];

bool cmpr(struct info *fir,struct info *sec)
{
	int lft1=(fir->loc)[0],lft2=sec->loc[0];
	if(lft1<lft2)		return 1;

	else if(lft1==lft2){
		int rgt1=(fir->loc)[1],rgt2=(sec->loc)[1];
		return (rgt1<=rgt2);
	}
	return 0;
}

int N;
list< VI >::iterator itf;

inline list< VI >::iterator ADD(list< VI > &fin, list< VI >::iterator pos,int str,int end,int num)
{
	VI tmp(3);
	tmp[0]=str,tmp[1]=end,tmp[2]=num;
	return fin.insert(pos,tmp);
}

void addPostr(list< VI > &fin, VI &now)
{
	VI tmp(3);
	int lft=now[0],rgt=now[1],idx=now[2];

	if(SZ(fin)==0){
		PB(fin,now);
		itf=fin.begin();
		return;
	}

	list< VI >::iterator cvr,last;
	bool chk=0;
	if(itf!=fin.begin()){
		last=itf,chk=1;
		last--;
	}

	bool dn=0;
	for(cvr=itf;cvr!=fin.end();cvr++){
		int tlf=(*cvr)[0],trt=(*cvr)[1],tin=(*cvr)[2];

		if(lft>rgt)		break;
		if(lft>trt)		continue;

		if(tlf>rgt){
			cvr=ADD(fin,cvr,lft,rgt,idx);
			if(!dn)		dn=1,itf=cvr;
			lft=rgt+1;
			break;
		}

		if(idx>tin){
			if(lft<=tlf && rgt<=trt){
				cvr=ADD(fin,cvr,lft,rgt,idx);
				if(!dn)		dn=1,itf=cvr;
				cvr++;

				if(rgt<trt){
					cvr=ADD(fin,cvr,rgt+1,trt,tin);
					cvr++;
				}
				lft=rgt+1;
				cvr=fin.erase(cvr);
				cvr--;
			} else if(tlf<=lft){
				if(tlf<lft){
					cvr=ADD(fin,cvr,tlf,lft-1,tin);
					cvr++;
				}

				int lim=(trt<=rgt)?trt:rgt;
				cvr=ADD(fin,cvr,lft,lim,idx);
				if(!dn)		dn=1,itf=cvr;
				cvr++;

				if(rgt<trt){
					cvr=ADD(fin,cvr,rgt+1,trt,tin);
					cvr++;
				}
				lft=lim+1;
				cvr=fin.erase(cvr);
				cvr--;
			}
		} else {
			if(lft<tlf){
				cvr=ADD(fin,cvr,lft,tlf-1,idx);
				if(!dn)		dn=1,itf=cvr;
				cvr++;
			}
			lft=trt+1,dn=1;
		}
	}

	if(lft<=rgt){
		tmp[0]=lft,tmp[1]=rgt,tmp[2]=idx;
		PB(fin,tmp);
		if(!dn){
			dn=1,itf=fin.end();
			itf--;
		}
	}

	if(chk){
		cvr=last;
		cvr++;
		while(cvr!=fin.end()){
			if((*cvr)[2]==(*last)[2]){
				(*last)[1]=(*cvr)[1];
				cvr=fin.erase(cvr);
				cvr--,last--;
			}
			cvr++,last++;
		}
	}
	return;
}

int main()
{
	int T;
	Input(T);
	while(T--){

		Input(N);
		FOR(inp,0,N){
			int lft,rgt;
			Input(lft),Input(rgt);
			pst[inp]=new info;
			pst[inp]->loc[0]=lft,pst[inp]->loc[1]=rgt;
			pst[inp]->ind=inp;
		}
		sort(pst,pst+N,cmpr);

		list< VI >fin;
		VI tmp(3);
		FOR(all,0,N){
			tmp[0]=pst[all]->loc[0],tmp[1]=pst[all]->loc[1],tmp[2]=pst[all]->ind;
			addPostr(fin,tmp);
		}

		MEM(prsnt,0);
		for(itf=fin.begin();itf!=fin.end();itf++)	prsnt[(*itf)[2]]=1;

		int ans=0;
		FOR(chk,0,N)	ans+=prsnt[chk];

		printf("%d\n",ans);
	}

	return 0;
}
