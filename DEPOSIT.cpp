#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define LL long long

using namespace std;

inline void Input(unsigned LL &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

inline unsigned LL fib(unsigned LL N)
{
	unsigned LL i=N-1,a=1,b=0,c=0,d=1,t;
	if(N<=0)	return 0;

	while(i>0){
		if(i&1){
			t=d*(b+a)+c*b;
 			a=d*b+c*a;
			b=t;
		}
		t=d*(2*c+d);
		c=c*c+d*d;
		d=t;
		i>>=1;
	}

	return a+b;
}

int main()
{
	unsigned LL T,k,r;
	unsigned LL x,y,S;

	Input(r);
	while(r!=0){
		Input(k),Input(T);

		if(r==2)
			printf("1 %llu %llu\n",T-1,k*(T-1));
		else {
			unsigned LL coefX=fib(r);
			unsigned LL coefY=fib(r+1)-1;
			unsigned LL lastX=fib(r-2);
			unsigned LL lastY=fib(r-1);

			S=0;
			for(unsigned LL tx=1;;tx++){
				unsigned LL tmp=(T-coefX*tx);

				if(tmp%coefY==0){
					unsigned LL val=lastX*tx+lastY*tmp/coefY;
					val*=k;
					S=val,x=tx,y=tmp/coefY;
					break;
				}
			}

			printf("%llu %llu %llu\n",x,y,S);
		}

		Input(r);
	}

	return 0;
}
