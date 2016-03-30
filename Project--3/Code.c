
//# code

#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<algorithm>
#define bool int
#define True 1
#define False 0


void get_binary_bits()
{	

	long Num;
	bool flag = 0 ;
	std::string set ; 
	while( Num )
{
		if( Num & 1 )
		{
			set += "True" ; 
		}
		else set += "False" ; 
		flag = 1; 
		Num >>= 1 ; 
	}
	if( flag ==0)  set += "False" ; 
	std::reverse( set.begin() , set.end() ) ;	
}

int new_bits()
{	
	int set = 0 ; 
	long Num;
	while(Num)
	{
		++set ; 
		Num >>= 1 ; 
	}
	return set ; 
}
bool set_bits( long long Bin_bits , int place )
{
	long m_value = 1 << place ; 
	if( Bin_bits & m_value ) return true ; 
	return false ; 
}
long long num_Arbitary(int n_bits , bool bit= 0)
{
	long long r_numb = 0 , one = 1 , face ; 
	int i , r ;
	if( bit)n_bits-=2 ; 
	for(i=0;i<n_bits;++i)
	{
		r = rand()%10 ; 
	
		if(r > 4 )
		{
			face = one << i ; 
			r_numb |= face ; 
		}
	} 
	if(bit)
	{
		face = one << ( n_bits - 2 ) ; 
		r_numb |= face ; 
	}
	return r_numb ; 
}
long long change_bits( long long Num , int place )
{
 long m_value = 1 << place ; m_value = ~m_value ;
	Num &= m_value ; 
	return Num ; 
	}

int main()
{
	long long Numerator , Divisor , Quotient , Remainder , Two_cmplmnt_D;  
	long long m_value , one = 1 ; 
	int i , n , repeat_bits ;
	int n_bits; 
	double cycle ;
	
	for( n = 16 ; n <= 32 ; n += 2 )
	{
		cycle = 0 ; 
		for(repeat_bits = 0 ; repeat_bits < 10000 ; ++repeat_bits )
		{
n_bits = n * 2 ; 
			Numerator = num_Arbitary( n_bits ) ;  
			m_value = one << n_bits ; 
			m_value -= 1 ; 
			
			while( Numerator == m_value || Numerator == 0 )
			{
				Numerator = num_Arbitary( n_bits ) ;  
			}
			
			Divisor = num_Arbitary( n , 1 ) ;  
			Two_cmplmnt_D = (~Divisor ) + 1 ; 
			Two_cmplmnt_D &= ((one<<n)-1) ; 
			Quotient = 0 ; 
			Remainder = 0 ; 
	 		for( i = n_bits - 1 ; i >= n  ; --i )
			{
				if( set_bits( Numerator  , i ) && set_bits( Numerator , i - 1 ) )
				{
					Quotient <<= 1 ;Quotient |= 1 ; 
					Numerator = change_bits( Numerator , i ) ; // removing the  bits 
					continue ; 
				}
					
				if( set_bits( Numerator  , i ) ==0 && set_bits( Numerator , i - 1 )==0 )
				{
					Quotient <<= 1 ; 
					continue ; 
				}
				break ; 
			}
			
			if( set_bits( Numerator  , i ) )
			{
				Quotient |= 1 ; 
				Quotient <<= 1 ; 
				Numerator += ( Divisor << (  i - n + 1 ) ) ; 				
				++cycle;
			}
			else
			{
				Quotient <<= 1 ; 
				Numerator += ( Two_cmplmnt_D << (  i - n + 1 ) ) ;
				++cycle;
			}
				bool tag = 0 ; 

			for( ; i >= n  ; ) 
			{
				Numerator &= ( ( one << (i+1) ) - 1 ) ; 
				tag = 0 ; 
				if( set_bits( Numerator , i ) )
				{
					Quotient <<= 1 ; Quotient |= 1 ;  
					Numerator = change_bits( Numerator , i ) ; 
					tag = 1 ; 
				
				}
				else
				{
					Quotient <<= 1 ; 
				}
				--i ; 

	 			for( ; i >= 0 ; --i )
				 {
					if( set_bits( Numerator  , i ) && set_bits( Numerator , i - 1 ) )
					{
						Quotient <<= 1 ;Quotient |= 1 ;  
						Numerator = change_bits( Numerator ,  i ) ; 
						continue ; 
					}	
				if( set_bits( Numerator  , i ) ==0 && set_bits( Numerator , i - 1 )==0 )
					{
				 		Quotient <<= 1 ; 
						continue ; 
					}
					break ;
				}
				if( tag )
				{
					Numerator += ( Divisor << (i-n+1) ) ;
					++cycle;
				}
				else 
				{
					Numerator += ( Two_cmplmnt_D << (i-n+1) ) ;
					++cycle;
				}
			}
			Remainder = Numerator & ((1<<n)-1);
			Quotient = Quotient & ((1<<(n+1))-1) ;
			}
		std::cout<<"\n\n\t 1).Random Value of the Numerator = "<<Numerator<<"\n\t";
		std::cout<<" 2).Random Value of the Divisor =  "<<Divisor<<"\n\t";
		std::cout<<" 3).Number of Bits Given for (n values) = "<<n<<"\n\t";
	std::cout<<" 4).Number of Addition/Subtraction cycle Average = "<< cycle/10000 <<"\n\t";
	}	
	return 0 ; 
}
