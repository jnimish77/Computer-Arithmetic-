//part:-1 of the project


#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

main()
{
	
   int n_bits;
   long int abit[32],bbit[32],sum[65], par_pro[32][32], c_in[33],p_a[33],m_a[33],t,delay=0, k;
   long int a_i,b_i,d,rem_1,rem_2,i,j,x,c_f,carryflag,size,flag[33],padd[33],p_sum[65],c_o[33],c_1[33],temp=0;
   
   

a_i=1207;
b_i=1737;
printf("%d\t%d\n",a_i,b_i);
printf("\n Enter the Number of Bits\n");
scanf("%d",&n_bits);
  
   for(k=0;k<=32;k++)
   {
   	
   	
   	delay=0;
   	for(d=1;d<=n_bits;d++)
   	{
   		rem_1=(a_i)%2;rem_2=(b_i)%2;
   		a_i=(a_i)/2;b_i=(b_i)/2;
   		abit[d]=rem_1; bbit[d]=rem_2;
   		
   			
	   }
	   
		
		
	   abit[n_bits+1]=0;bbit[n_bits+1]=0;
	   for(i=n_bits+1;i>=1;i--)
	  printf("%d\t%d\n",abit[i],bbit[i]);
	   for(i=1;i<=n_bits+1;i++)
	   {
	   	
	   	p_a[i]=abit[i];
	   	m_a[i]=(!abit[i]);
	   	printf("\n %d %d\t",p_a[i],m_a[i]);
	   	
	   }
	   printf("\n");
	   for(i=1;i<=n_bits+1;i++)
	   {
	   	
	   	if(bbit[i]==1)	
	   	
	   	{
	   	    if(bbit[i-1]==0)
	   	    
			   
			   flag[i]=2;
		
			   else flag[i]=0;	
		   }
		   else if(bbit[i]==0)
		   {
		   	if(bbit[i-1]==1)
		   	flag[i]=1;
		   	else flag[i]=0;
		   }
	   }
	   
	   
	   printf("recoded bits ==");
	   for(i=1; i<=n_bits+1;i++)
	   printf("%d%", flag[i]);
	   printf("\n");
   	for(i=1;i<=n_bits+1;i++)
   	{
   		c_o[1]=1;carryflag=0;
   		for(j=1;j<=n_bits+1;j++)
   		{
   			
   			carryflag=0;
   			if(flag[i]==1)
   			{
   				padd[j]=p_a[j];
   				c_in[1]=0;
   			
			   }
			   else if(flag[i]==2)
			   {
			   	padd[j]=m_a[j];c_in[1]=1;
			   	
			   }
			   else if(flag[i]==0)
			   {
			   	padd[j]=0;
			   	c_in[1]=0;
			   	
			   }
			   
			   temp=p_sum[j+i-1];
			   p_sum[j+i-1]= (p_sum[j+i-1]^padd[j]^c_in[j]);
			   c_in[j+1]=((temp^padd[j]) & c_in[j]) | (temp & padd[j]);
			   c_o[j+1]=((!temp) && (!padd[j])) || ((temp^ padd[j]) && (c_o[j]));
			   c_1[j+1]=((temp) && (padd[j])) || ((temp ^ padd[j]) && (c_1[j]));
			   if(j==(n_bits+1))
			   p_sum[j+1]=p_sum[j+i-1];
		   }
		   
		   if (flag[i]==1 || flag[i]==2)
		   {
		   	for(c_f=1;c_f<=2*n_bits;c_f++)
		   	{
		   		
		   		carryflag=carryflag+c_in[c_f];
		   		if(carryflag!=0)
		   		delay=delay+1;
			   }
		   }
		   else delay=delay;
	   }
	   
	   
	   for(x=1;x<=2*n_bits;x++)
	   printf("%d", p_sum[x]);
	  printf("\n Total delay for a*b == %d \n",d*(d*2+4)); 

   }
	
	
	
	
}
