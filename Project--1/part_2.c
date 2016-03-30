#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int counter=0;
int arrayA[48],arrayB[48],C0[48],C1[48],Ci1[48],Ci0[48];
int i,j,k, l, m,n;
int numberofbits;
int delay;   
int main() 
{
    
    printf("Enter Number of Bits : ");
    scanf("%d", &numberofbits);
    
    if((numberofbits>2)&&(numberofbits<=48))
    {
        //for(k=0;k<1000;k++)
        //{
            printf("enter the operand A");
            for(i=0;i<numberofbits;i++)
            {
                scanf("%d", &arrayA[i]);
                //arrayA[i]=rand()%2;
                
            }
            C0[numberofbits]=0;
            Ci0[numberofbits]=0;
            Ci1[0]=1;
            C1[0]=1;
            printf("enter the operand B");
            for(i=0;i<numberofbits;i++)
            {
                scanf("%d", &arrayB[i]);
                //arrayB[i]=rand()%2;
            }
    
             while(counter<numberofbits)
            {
                delay++;
                for(j=0;j<numberofbits;j++)
                {
                    Ci1[j+1]=(arrayA[j]&arrayB[j])|(C1[j]&(arrayA[j]^arrayB[j]));
                    Ci0[j+1]=(((~arrayA[j])&(~arrayB[j]))|(C0[j]&(arrayA[j]^arrayB[j])))+2;
                
                    printf("Ci1[%d] = %d\n", j, Ci1[j]);
                    printf("Ci0[%d] = %d\n", j, Ci0[j]);
                    
              
                    for(l=0;l<numberofbits;l++)
                    {
                        if(((C1[l])^(C0[l]))==1)
                        {
                            counter++;
                        }   
                        else
                        {
                            counter=0;
                        }
                    }
                    
                    C1[j]=Ci1[j];
                    C0[j]=Ci0[j];
                
                    printf("C1[%d] = %d\n", j, C1[j]);
                    printf("C0[%d] = %d\n", j, C0[j]);
                   
                
                }
                
                printf("the counter is : %d \n", counter);
            }
            
            printf("The carry out c1 is\n");
            for(n=0;n<numberofbits;n++)
            {
                printf("%d\n", C1[n]);
            }
            
            printf("The carry out c0 is\n");
            for(m=0;m<numberofbits;m++)
            {
                printf("%d",C0[m]);
            }
            
            printf("\nThe total delay is ");
            printf("%d\n", delay*2);
        //}
    }
    else
        printf("Enter the correct size of the operands\n");
    return 0;
}
