#include <stdio.h>

int main() {
    
    int direct[100][100]={0,};
    int i,j;
    int exist=0;
    int n;/*几行几列*/
    int maxid[100] ={0,};
    int minid[100] ={0,};
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&direct[i][j]);
	}
    for(i=0;i<n;i++)
	{
        maxid[i]=direct[i][0];
        for( j =0;j<n;j++)
        {
            if(direct[i][j]>maxid[i]){
                maxid[i]=direct[i][j];
            }
        }
    }
    for(j=0;j<n;j++){
        minid[j]=direct[1][j];
        for(  i =0;i<n;i++)
        {
            if(direct[i][j]<minid[j]){
                minid[j]=direct[i][j];
            }
        }
        }

    for(i=0;i<n;i++) 
	{
		for(j=0;j<n;j++)
		{
			if(minid[j]==maxid[i])	
			{
				printf("%d %d",i,j);
				exist=1;			
			}
		}
	}
	if(0==exist) 
	{
		printf("NO");
	}

  
    return 0;
}
