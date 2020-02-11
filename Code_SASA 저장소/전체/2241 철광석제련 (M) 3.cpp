#include<cstdio>
#define M 1000
int max,sum,map[M+1][M+1],n;
int readInt(){
	int sum=0;
	char now=getchar();
	while(now<=32) now=getchar();
	while(now>=48){
		sum = sum*10+now-48;
		now=getchar();
	}
	return sum;
}
int main(){
	n=readInt();
	for(int i=1;i<=n;i++)
		for(int j=1,k;j<=n;j++){
			k=readInt();
			map[i][j]=k+map[i-1][j]+map[i][j-1]-map[i-1][j-1];
		}
	if(n<100) printf("%d",map[n][n]);
	else{
	for(int i=1;i<=n-99;i++)
		for(int j=1;j<=n-98;j++){
			sum=map[i+99][j+98]-map[i+99][j-1]-map[i-1][j+98]+map[i-1][j-1];
			if(sum>max)
				max=sum;
		}
	printf("%d",max);
}
}
