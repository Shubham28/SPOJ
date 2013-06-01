#include <algorithm>
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

inline void Input(LL &in)
{
	int ch;
	in=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		in=(in<<3)+(in<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

//	Project Euler Problem 21

#define N 100000100
unsigned int prime[N/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	MEM(prime,-1);

	unsigned int i;
	unsigned int sqrtN=(unsigned int)sqrt((double)N)+1;
	for(i=3;i<sqrtN;i+=2) if(gP(i))
	{
		unsigned int i2=i+i;
		for(unsigned int j=i*i;j<N;j+=i2) 	rP(j);
	}
}

int prm[5761470],L=0;

LL expn(LL base,int exp)
{
	if(exp==1)		return base;

	LL tmp=expn(base,exp>>1);
	if(exp&1)
		return tmp*tmp*base;
	else
		return tmp*tmp;
}

LL sumDiv(LL num)
{
	LL cnt=1;

	for(int chk=0;(LL)prm[chk]*(LL)prm[chk]<=num;chk++)
		if(num==(num/(LL)prm[chk])*(LL)prm[chk]){

			int exp=0;
			while(num==(num/(LL)prm[chk])*(LL)prm[chk])
				++exp,num/=prm[chk];

			cnt*=((expn(prm[chk],exp+1)-1)/(prm[chk]-1));
		}

	if(num>1)	cnt*=(num+1);

	return cnt;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	sieve();
	prm[L++]=2;		prm[L++]=3;
	for(int ml=1;ml*6<=(N-100);ml++){
		if(gP(ml*6-1))		prm[L++]=ml*6-1;
		if(gP(ml*6+1))		prm[L++]=ml*6+1;
	}

	int T;
	scanf("%d",&T);
	while(T--){
		LL nm;
		Input(nm);
		if(nm<=(N-100) && (nm&1) && gP(nm))
			printf("1\n");
		else
			printf("%lld\n",sumDiv(nm)-nm);
	}

//	fclose(stdin);
	return 0;
}
