#include <algorithm>
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int ch,sign;

inline void Input(int &N)
{
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+ch-'0';
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}


int main()
{
	int T;
	Input(T);

	while(T--){
		int num,cnt=0;
		Input(num);

		for(int pwr=5;pwr<=num;){
			cnt=cnt+(num/pwr);
			pwr=(pwr<<2)+pwr;
		}

		printf("%d\n",cnt);
	}

	return 0;
}

