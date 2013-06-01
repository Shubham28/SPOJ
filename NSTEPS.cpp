#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T=2;
	scanf("%d",&T);

	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);

		if(!(x==y || (x-y)==2)){
			printf("No Number\n");
			continue;
		}
		int ans;

		if(x==y)
			ans=(x%2==0)?x*2:(x*2-1);
		else
			ans=(y%2==0)?(y*2+2):(y*2+1);
		printf("%d\n",ans);
	}

	return 0;
}
