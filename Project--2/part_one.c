
//first part of the project

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

main()
{
	int n_bits;
	
	long int a[33],b[33],sum[65],par_pro[32][32],c_in[33],temp[65];
	
	long int ai,bi,d,rem_1,rem_2,i,j,x,loop;
	
	FILE *fp=NULL;
	fp=fopen("CCA_out.txt","wt+");
	
	if(fp==NULL)
	
	printf("Error in File Opening\n");
	
	for(loop=2;loop<=32;loop++)
	
	{
		
		ai=rand();
		bi=rand();
		printf("%d\t%d\n",ai,bi);
		n_bits=loop;
		
		
		for(d=1;d<=n_bits;d++)
		
		{
			
			
			rem_1=ai%2;rem_2=bi%2;
			ai=ai/2;bi=bi/2;
			a[d]=rem_1;b[d]=rem_2;
			
		}
		
		printf("a=");
		for(i=n_bits;i>=1;i--)
		printf("%d", a[i]);
		printf("\n");
		printf("b=");
		for(i=n_bits;i>=1;i--)
		printf("%d",b[i]);
		printf("\n");
		printf("\n the partial product=");
		for(i=1;i<=n_bits;i++)
		{
			
		  printf("\n");
		  for(j=1;j<=n_bits;j++)
		  
		  {
		  	
		  	par_pro[i][j]=a[i]&b[i];
		  	printf("%d",par_pro[i][j]);
		  	
		  }
		}
		printf("\n");
	/*	for(i=1;i<=n_bits;i++)
		{
			
			int c_in[33]={0};
			for(j=1;j<=n_bits;j++)
			
			
			{
				
				
			}
		}*/
		
		
		
		
	
		
		
		
	}
	
	
	
	
}


*******************************************************************************************************************************




#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

main()
{
	int n_bits;
	
	long int a[33],b[33],sum[65],par_pro[32][32],c_in[33],temp[65];
	
	long int ai,bi,d,rem_1,rem_2,i,j,x,loop;
	
	FILE *fp=NULL;
	fp=fopen("CCA_out.txt","wt+");
	
	if(fp==NULL)
	
	printf("Error in File Opening\n");
	
	for(loop=2;loop<=32;loop++)
	
	{
		
		ai=rand();
		bi=rand();
		printf("%d\t%d\n",ai,bi);
		n_bits=loop;
		
		
		for(d=1;d<=n_bits;d++)
		
		{
			
			
			rem_1=ai%2;rem_2=bi%2;
			ai=ai/2;bi=bi/2;
			a[d]=rem_1;b[d]=rem_2;
			
		}
		
		printf("a=");
		for(i=n_bits;i>=1;i--)
		printf("%d", a[i]);
		printf("\n");
		printf("b=");
		for(i=n_bits;i>=1;i--)
		printf("%d",b[i]);
		printf("\n");
		printf("\n the partial product=");
		for(i=1;i<=n_bits;i++)
		{
			
		  printf("\n");
		  for(j=1;j<=n_bits;j++)
		  
		  {
		  	
		  	par_pro[i][j]=a[i]&b[i];
		  	printf("%d",par_pro[i][j]);
		  	
		  }
		}
		printf("\n");
		for(i=1;i<=n_bits;i++)
		{
			
			int c_in[33]={0};
			for(j=1;j<=n_bits;j++)
			
			
			{
			if(i==1)
			{
				
				sum[1]=par_pro[1][1];
				sum[j+i]=par_pro[i][j+1]^par_pro[i+1][j]^c_in[j];
				c_in[j+1]=((par_pro[i][j+1]^par_pro[i+1][j])&c_in[j]) | (par_pro[i][j+1] & par_pro[i+1][j]);
				
				if(j==n_bits)
				sum[j+i+10]=c_in[j+1];
			}
			
			else
			{
				temp[j+1]=sum[j+1];
				sum[j+1]=sum[j+1]^par_pro[i+1][j]^c_in[j];
				c_in[j+1]=((temp[j+i]^par_pro[i+1][j])& c_in[j]) | (temp[j+1] & par_pro[i+1][j]);
				if(j=n_bits)
				sum[i+j+1]=c_in[j+1];
			
			}
			}
			
			
		
			
				
			}
			
			for(i=(n_bits*2)+1;i>=1;i--)
			printf("%d", sum[i]);
			printf("\n");
			printf("\n total delay(2nd+2d+2d)n +d of ===%d \n", (n_bits*(4+2*n_bits)+1));
			fprintf(fp, "%d\n", (n_bits*(4+(2*n_bits))+1));
			
		}
		
		
		
		
	
		
		
		
	}
	
	
	
	











