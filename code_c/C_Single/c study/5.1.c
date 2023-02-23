#include<stdio.h>
int main()
{
	int n,m;
    int r=0;//素数个数
	int sum=0;
	int flag = 1; 
	int x=2;
	scanf("%d %d",&n,&m);
	while (0<n && n<=m && m<200)
	{	
		 //遍历前m个的素数 
		while(r < m){
			//判断一个数是否是素数
			flag = 1;   
			int i ;
			for(i = 2; i < x; i++){
				if( x % i == 0){
					flag = 0; 
					break;
				}
			}
			if( flag ){
				r++;
				//如果是第n个素数则开始录入sum 
				if( r>= n ){
					sum += x;
				}
			}
			x++;
		}
		printf("%d",sum);
		goto out;
	}
	printf("你的数据不符！");
out:
	return 0;
}