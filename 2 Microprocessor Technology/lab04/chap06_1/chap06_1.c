/*************************************************************************
Include files
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "driver.h"

/*************************************************************************
Variables
*************************************************************************/
int i,j,k;
unsigned short io_reg2;
unsigned short io_reg1;
/*************************************************************************
System Initialize
*************************************************************************/
void Initial_Creator(void)
{
        Initial_TIMER0();
        Initial_KEYPAD();
}

const UC LED_tb2[] = {
		0xdf, 0xde, 0xfe, 0xfe, 0xfe,
		0xfc, 0xf8, 0xf0, 0xf6, 0xf6,
		0xd6, 0xc6
		}; // 右無全開
const UC LED_tb1[] = {
		0xdf, 0x9e, 0xbe, 0xbe, 0xbe,
		0xbc, 0xb8, 0xb0, 0xb6, 0xb6,
		0x96, 0x86
		}; // 右有全開		
const UC LED_tb3[] ={	
	    0xef, 0xe7, 0xf7, 0xf7, 0xf7,
		0xf3, 0xf1, 0xf0, 0xf6, 0xf6,
		0xe6, 0xc6
        }; // 左無全開   20->9;
const UC LED_tb4[] ={	
	    0xaf, 0xa7, 0xb7, 0xb7, 0xb7,
		0xb3, 0xb1, 0xb0, 0xb6, 0xb6,
		0xa6, 0x86
        }; // 左有全開
/*************************************************************************
MAIN Program 
*************************************************************************/
int main(void)
{
 
    
    Initial_Creator();         
	//EnableInterrupt(BIT_GMASK);
	i=0,j=0,k=0;
	
    while (10)
    {   
	    io_reg1 =IO_REG1;
		io_reg1 =io_reg1 | 0xfffb;
		if(io_reg1 == 0xfffb)//3 open
		{
//--------------------------------------
		io_reg1 =IO_REG1;
		io_reg1 =io_reg1 | 0xfffe;
        if(io_reg1 == 0xfffe) // 1開 向左
		{
            io_reg1=IO_REG1;
            io_reg1=io_reg1 | 0xfffd;
            if(io_reg1 == 0xfffd)
            {
            	k=(k+1)%21;
            	if(k==0)  //2 open
            	{
            		IO_REG2 = 0xffff;
            		Delay(1);
            		for(j=0;j<100;j++)
            		{
                        		IO_REG0 =0xfeff ;
                        		IO_REG0 =0xfdff ;
                        		IO_REG0 =0xfbff ;
                        		IO_REG0 =0xf7ff ;
                        		Delay(1);
            		}
            	}
            	else if(k==13)
            	{
					
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							 IO_REG2 = 0x7fff;
                             Delay(10);
					         IO_REG2 = 0xffff;
                             Delay(10);
            		}            		
					 
            	}
            	else if(k==14)
            	{
            		
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							IO_REG2 = 0x3fff;
            		        Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}   
            	}
            	else if(k==15)
            	{
            		 
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							IO_REG2 = 0x1fff;
            		        Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}   
            	}
            	else if(k==16)
            	{
                   
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10);
							 IO_REG2 = 0x0fff;
            		        Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
                }
            	else if(k==17)
            	{
            		
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							 IO_REG2 = 0x07ff;
                             Delay(10); 
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==18)
            	{
            		
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							IO_REG2 = 0x03ff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==19)
            	{
            		 
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							IO_REG2 = 0x01ff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==20)
            	{
                     
					for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							 IO_REG2 = 0x00ff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}     
            	}
            	else if(k==1 || k==2)
            	{
            		for(j=0;j<10;j++)
                		{
            				IO_REG0 =0xfe00 + LED_tb3[k-1];
                			Delay(10);
							IO_REG0 =0xfeff;
                			Delay(10);
                		}
            	}	
            	else if(k==3)
                	{
                		for(j=0;j<10;j++)
                		{
                			IO_REG0=0xfe00 + LED_tb3[1];
            			    Delay(10);
            			    IO_REG0=0xfd00 + LED_tb3[k-1];
							Delay(10); 
                		}
                	}
            	else if(k==4)
            	{
            		for(j=0;j<10;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[2];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[k-1];	
                    		Delay(10); 
            		}
            	}
            	else if(k==5||k==6||k==7||k==8)
            	{
            		for(j=0;j<10;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[2];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[3];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[k-1];
                    		Delay(10); 
            		}
            	}
            	else if(k==9)
            	{
            		for(j=0;j<10;j++)
            		{
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							IO_REG0 =0xfb00 + LED_tb3[k-1];	
                    		Delay(10); 
							IO_REG0 =0xfd00 + LED_tb3[2];
                    		Delay(10); 
							IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(10); 
            		}
            	}
            	else if(k==10)
            	{
            		for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
							IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10);
                    		IO_REG0 =0xfd00 + LED_tb3[k-1];
							Delay(10); 
                    		IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(10); 
            		}
            	}
            	else
            	{
            		for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[k-1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(10); 
            		}
            	}
            }
            else
            {
                k=(k+1)%21;
            	if(k==0)  //2 open
            	{
            		IO_REG2 = 0xffff;
            		Delay(1);
            		for(j=0;j<100;j++)
            		{
                        		IO_REG0 =0xfeff ;
                        		IO_REG0 =0xfdff ;
                        		IO_REG0 =0xfbff ;
                        		IO_REG0 =0xf7ff ;
                        		Delay(1);
            		}
            	}
            	else if(k==13)
            	{
					         		
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							IO_REG2 = 0x7fff;
                    		 Delay(10);   
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==14)
            	{
            		
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							IO_REG2 = 0x3fff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==15)
            	{
            		
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							IO_REG2 = 0x1fff;
            				Delay(10); 
							IO_REG2 = 0xffff;
                            Delay(10);
            		}   
            	}
            	else if(k==16)
            	{
                    
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							IO_REG2 = 0x0fff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}   
                }
            	else if(k==17)
            	{
            		
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							 IO_REG2 = 0x07ff;
                   			 Delay(10); 
							IO_REG2 = 0xffff;
                            Delay(10);
            		}   
            	}
            	else if(k==18)
            	{
            		
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							IO_REG2 = 0x03ff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==19)
            	{
            		
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							 IO_REG2 = 0x01ff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}  
            	}
            	else if(k==20)
            	{
                     
					 for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
							IO_REG2 = 0x00ff;
            				Delay(10);
							IO_REG2 = 0xffff;
                            Delay(10);
            		}       
            	}
            	else if(k==1 || k==2)
            	{
            		for(j=0;j<10;j++)
                		{
            				IO_REG0 =0xfe00 + LED_tb4[k-1];
                			Delay(10);
							IO_REG0 =0xfeff;
                			Delay(10);
                		}
            	}	
            	else if(k==3)
                	{
                		for(j=0;j<10;j++)
                		{
                			IO_REG0=0xfe00 + LED_tb4[1];
            			    Delay(10);
            			    IO_REG0=0xfd00 + LED_tb4[k-1];
							Delay(10); 
                		}
                	}
            	else if(k==4)
            	{
            		for(j=0;j<10;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[2];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[k-1];	
                    		Delay(10); 
            		}
            	}
            	else if(k==5||k==6||k==7||k==8)
            	{
            		for(j=0;j<10;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[2];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[3];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[k-1];
                    		Delay(10); 
            		}
            	}
            	else if(k==9)
            	{
            		for(j=0;j<10;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[2];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[k-1];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
            		}
            	}
            	else if(k==10)
            	{
            		for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[k-1];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
            		}
            	}
            	else
            	{
            		for(j=0;j<10;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[k-1];
                    		Delay(10); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(10); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(10); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(10); 
            		}
            	}
                  
            }		   
		}
//-----------------------------------------------------------------------------//        
        else                 //1關  向右
		{
            io_reg1 =IO_REG1;
		    io_reg1 =io_reg1 | 0xfffd;
		    if(io_reg1 == 0xfffd) // 2開 啟 用
		    {    
                i=(i+1)%21; 
		        if(i==0)   // 全暗
		        {
		            IO_REG2 = 0xffff;
			        Delay(1);
			        for(j=0;j<100;j++)
			        {
            		    IO_REG0 =0xfeff ;
            			IO_REG0 =0xfdff ;
            			IO_REG0 =0xfbff ;
            			IO_REG0 =0xf7ff ;
            			Delay(1);
			        }
		        }
		        else if(i==1)
		        {   
				    for(j=0;j<10;j++)
			        {
        		     IO_REG2 = 0xfeff;
        		     Delay(10);
					 IO_REG2 = 0xffff;
        		     Delay(10); 
					}
		        }
		        else if(i==2)
		        {   
				     for(j=0;j<10;j++)
			        {
        		    IO_REG2 = 0xfcff;
        		    Delay(10);
					IO_REG2 = 0xffff;
        		    Delay(10); 
					}
		        }
		        else if(i==3)
		        {
            		 for(j=0;j<10;j++)
			        {
					IO_REG2 = 0xf8ff;
            	    Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
					}
		        }
		        else if(i==4)
		        {
            		 for(j=0;j<10;j++)
			        {
					IO_REG2 = 0xf0ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
					}
            	}
		        else if(i==5)
		        {
		             for(j=0;j<10;j++)
			        {
					IO_REG2 = 0xe0ff;
		            Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
		            }
				}
		        else if(i==6)
		        {
		            for(j=0;j<10;j++)
			        {
					IO_REG2 = 0xc0ff;
		            Delay(10);
					IO_REG2 = 0xffff;
        		    Delay(10); 
					}
		        }
		        else if(i==7)
		        {
		             for(j=0;j<10;j++)
			        {
					IO_REG2 = 0x80ff;
		            Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
		            }
				}
		        else if(i==8)
		        {
            		 for(j=0;j<10;j++)
			        {
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
		            }
				}
		        else if(i==9||i==10)
		        {
		             for(j=0;j<10;j++)
			        {
					IO_REG0 =0xfe00 + LED_tb1[i-9];
		            Delay(10);
					IO_REG0 =0xfeff;
		            Delay(10);
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
		            }
					
		        }
			    else if(i==11)
		        {
		              for(j=0;j<10;j++)
			         {
                			IO_REG0 =0xfe00 + LED_tb1[1];
                			Delay(10);    
                		    IO_REG0 =0xfd00 + LED_tb1[i-9];	
                			Delay(10); 
					       IO_REG2 = 0x00ff;
            		      	Delay(10); 
							IO_REG2 = 0xffff;
        		   			 Delay(10);		
			        }
			    }
		      else if(i==12)
		      {
		          for(j=0;j<10;j++)
			     {
        		    IO_REG0 =0xfe00 + LED_tb1[1];
        			Delay(10); 
        		    IO_REG0 =0xfd00 + LED_tb1[2];
        			Delay(10); 
        			IO_REG0 =0xfb00 + LED_tb1[i-9];	
        			Delay(10); 
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
			     }
		      }
		      else if(i==13||i==14||i==15||i==16)
		      {
		          for(j=0;j<10;j++)
			    {
        		    IO_REG0 =0xfe00 + LED_tb1[1];
        		    Delay(10); 
        			IO_REG0 =0xfd00 + LED_tb1[2];
        			Delay(10); 
        			IO_REG0 =0xfb00 + LED_tb1[3];	
        			Delay(10); 
        			IO_REG0 =0xf700 + LED_tb1[i-9];
        			Delay(10);
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10); 
			     }
		      }	
		      else if(i==17)
		      {
		          for(j=0;j<10;j++)
			     {
        			IO_REG0 =0xfe00 + LED_tb1[1];
        		    Delay(10); 
        			IO_REG0 =0xfd00 + LED_tb1[2];
        			Delay(10); 
        			IO_REG0 =0xfb00 + LED_tb1[i-9];	
        			Delay(10); 
        			IO_REG0 =0xf700 + LED_tb1[7];
        			Delay(10); 
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
			     }
		      }
		      else if(i==18)
		      {
		          for(j=0;j<10;j++)
			     {
        		    IO_REG0 =0xfe00 + LED_tb1[1];
        		    Delay(10); 
        			IO_REG0 =0xfd00 + LED_tb1[i-9];
        			Delay(10); 
        			IO_REG0 =0xfb00 + LED_tb1[8];	
        			Delay(10); 
        			IO_REG0 =0xf700 + LED_tb1[7];
        			Delay(10);
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10); 
			     }
		      }
		      else 
		      {
        		   for(j=0;j<10;j++)
        		{
        			IO_REG0 =0xfe00 + LED_tb1[i-9];
        		    Delay(10); 
        			IO_REG0 =0xfd00 + LED_tb1[9];
        			Delay(10); 
        			IO_REG0 =0xfb00 + LED_tb1[8];	
        			Delay(10); 
        			IO_REG0 =0xf700 + LED_tb1[7];
        			Delay(10); 
					IO_REG2 = 0x00ff;
            		Delay(10); 
					IO_REG2 = 0xffff;
        		    Delay(10);
        		}
		      }
		    } 
    		   else    // 2開 不啟 用
    		   {
    		   i=(i+1)%21; 
    		   if(i==0) // 全暗
    		   {
    		   IO_REG2 = 0xffff;
    			Delay(1);
    			for(j=0;j<100;j++)
    			{
    		    IO_REG0 =0xfeff ;
    			IO_REG0 =0xfdff ;
    			IO_REG0 =0xfbff ;
    			IO_REG0 =0xf7ff ;
    			Delay(1);
    			}
    		   }
    		   else if(i==1)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0xfeff;
    		   Delay(10); 
			   IO_REG2 = 0xffff;
        		    Delay(10);
					}
    		   }
    		   else if(i==2)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0xfcff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
					}
    		   }
    		   else if(i==3)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0xf8ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
					}
    		   }
    		   else if(i==4)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0xf0ff;
    		   Delay(10); 
			   IO_REG2 = 0xffff;
        		    Delay(10);
					}
    		   }
    		   else if(i==5)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0xe0ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
					}
    		   }
    		   else if(i==6)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0xc0ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
					}
    		   }
    		   else if(i==7)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0x80ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
					}
    		   }
    		   else if(i==8)
    		   {
			   for(j=0;j<10;j++)
    			{
    		   IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
					}
    		   }
    		   else if(i==9||i==10)
    		   {
    		    for(j=0;j<10;j++)
    			{
				IO_REG0 =0xfe00 + LED_tb2[i-9];
    		    Delay(10); 
				IO_REG0 =0xfeff;
    		    Delay(10); 
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
				}
    			}	
    			else if(i==11)
    		   {
    		    for(j=0;j<10;j++)
    			{
    			IO_REG0 =0xfe00 + LED_tb2[1];
    			Delay(10);    
    		    IO_REG0 =0xfd00 + LED_tb2[i-9];	
    			Delay(10); 
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
    			}
    			}
    		   else if(i==12)
    		   {
    		   for(j=0;j<10;j++)
    			{
    		    IO_REG0 =0xfe00 + LED_tb2[1];
    			Delay(10); 
    		    IO_REG0 =0xfd00 + LED_tb2[2];
    			Delay(10); 
    			IO_REG0 =0xfb00 + LED_tb2[i-9];	
    			Delay(10); 
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
    			}
    		   }
    		   else if(i==13||i==14||i==15||i==16)
    		   {
    		   for(j=0;j<10;j++)
    			{
    		    IO_REG0 =0xfe00 + LED_tb2[1];
    		    Delay(10); 
    			IO_REG0 =0xfd00 + LED_tb2[2];
    			Delay(10); 
    			IO_REG0 =0xfb00 + LED_tb2[3];	
    			Delay(10); 
    			IO_REG0 =0xf700 + LED_tb2[i-9];
    			Delay(10); 
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
    			}
    		   }	
    		   else if(i==17)
    		   {
    		    for(j=0;j<10;j++)
    			{
    			IO_REG0 =0xfe00 + LED_tb2[1];
    		    Delay(10); 
    			IO_REG0 =0xfd00 + LED_tb2[2];
    			Delay(10); 
    			IO_REG0 =0xfb00 + LED_tb2[i-9];	
    			Delay(10); 
    			IO_REG0 =0xf700 + LED_tb2[7];
    			Delay(10);
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10);  
    			}
    		   }
    		   else if(i==18)
    		   {
    		   for(j=0;j<10;j++)
    			{
    		    IO_REG0 =0xfe00 + LED_tb2[1];
    		    Delay(10); 
    			IO_REG0 =0xfd00 + LED_tb2[i-9];
    			Delay(10); 
    			IO_REG0 =0xfb00 + LED_tb2[8];	
    			Delay(10); 
    			IO_REG0 =0xf700 + LED_tb2[7];
    			Delay(10);
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10);  
    			}
    		   }
    		   else 
    		   {
    		   for(j=0;j<10;j++)
    			{
    			IO_REG0 =0xfe00 + LED_tb2[i-9];
    		    Delay(10); 
    			IO_REG0 =0xfd00 + LED_tb2[9];
    			Delay(10); 
    			IO_REG0 =0xfb00 + LED_tb2[8];	
    			Delay(10); 
    			IO_REG0 =0xf700 + LED_tb2[7];
    			Delay(10); 
				 IO_REG2 = 0x00ff;
    		   Delay(10);
			   IO_REG2 = 0xffff;
        		    Delay(10); 
    			}
    		   }
    		  }
			   
    		  }
		   }
//---------------------------------------------------閃爍
          else
		  {
		  io_reg1 =IO_REG1;
		io_reg1 =io_reg1 | 0xfffe;
        if(io_reg1 == 0xfffe) // 1開 向左
		{
            io_reg1=IO_REG1;
            io_reg1=io_reg1 | 0xfffd;
            if(io_reg1 == 0xfffd)
            {
            	k=(k+1)%21;
            	if(k==0)  //2 open
            	{
            		IO_REG2 = 0xffff;
            		Delay(1);
            		for(j=0;j<100;j++)
            		{
                        		IO_REG0 =0xfeff ;
                        		IO_REG0 =0xfdff ;
                        		IO_REG0 =0xfbff ;
                        		IO_REG0 =0xf7ff ;
                        		Delay(1);
            		}
            	}
            	else if(k==13)
            	{
					IO_REG2 = 0x7fff;
                     Delay(1);
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}            		
					 
            	}
            	else if(k==14)
            	{
            		IO_REG2 = 0x3fff;
            		Delay(1);
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}   
            	}
            	else if(k==15)
            	{
            		IO_REG2 = 0x1fff;
            		Delay(1); 
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}   
            	}
            	else if(k==16)
            	{
                    IO_REG2 = 0x0fff;
            		Delay(1);
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}  
                }
            	else if(k==17)
            	{
            		 IO_REG2 = 0x07ff;
                    Delay(1); 
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==18)
            	{
            		IO_REG2 = 0x03ff;
            		Delay(1);
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==19)
            	{
            		 IO_REG2 = 0x01ff;
            		Delay(1);
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==20)
            	{
                     IO_REG2 = 0x00ff;
            		Delay(1); 
					for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}     
            	}
            	else if(k==1 || k==2)
            	{
            		for(j=0;j<100;j++)
                		{
            				IO_REG0 =0xfe00 + LED_tb3[k-1];
                			Delay(1);
                		}
            	}	
            	else if(k==3)
                	{
                		for(j=0;j<100;j++)
                		{
                			IO_REG0=0xfe00 + LED_tb3[1];
            			    Delay(1);
            			    IO_REG0=0xfd00 + LED_tb3[k-1];
							Delay(1); 
                		}
                	}
            	else if(k==4)
            	{
            		for(j=0;j<70;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[2];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[k-1];	
                    		Delay(1); 
            		}
            	}
            	else if(k==5||k==6||k==7||k==8)
            	{
            		for(j=0;j<50;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[2];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[3];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[k-1];
                    		Delay(1); 
            		}
            	}
            	else if(k==9)
            	{
            		for(j=0;j<50;j++)
            		{
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
							IO_REG0 =0xfb00 + LED_tb3[k-1];	
                    		Delay(1); 
							IO_REG0 =0xfd00 + LED_tb3[2];
                    		Delay(1); 
							IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(1); 
            		}
            	}
            	else if(k==10)
            	{
            		for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
							IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1);
                    		IO_REG0 =0xfd00 + LED_tb3[k-1];
							Delay(1); 
                    		IO_REG0 =0xfe00 + LED_tb3[1];
                    		Delay(1); 
            		}
            	}
            	else
            	{
            		for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb3[k-1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb3[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb3[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb3[7];
                    		Delay(1); 
            		}
            	}
            }
            else
            {
                k=(k+1)%21;
            	if(k==0)  //2 open
            	{
            		IO_REG2 = 0xffff;
            		Delay(1);
            		for(j=0;j<100;j++)
            		{
                        		IO_REG0 =0xfeff ;
                        		IO_REG0 =0xfdff ;
                        		IO_REG0 =0xfbff ;
                        		IO_REG0 =0xf7ff ;
                        		Delay(1);
            		}
            	}
            	else if(k==13)
            	{
					IO_REG2 = 0x7fff;
                        Delay(1);            		
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==14)
            	{
            		IO_REG2 = 0x3fff;
            		Delay(1);
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==15)
            	{
            		IO_REG2 = 0x1fff;
            		Delay(1); 
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}   
            	}
            	else if(k==16)
            	{
                    IO_REG2 = 0x0fff;
            		Delay(1);
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}   
                }
            	else if(k==17)
            	{
            		 IO_REG2 = 0x07ff;
                    Delay(1); 
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}   
            	}
            	else if(k==18)
            	{
            		IO_REG2 = 0x03ff;
            		Delay(1);
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==19)
            	{
            		 IO_REG2 = 0x01ff;
            		Delay(1);
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}  
            	}
            	else if(k==20)
            	{
                     IO_REG2 = 0x00ff;
            		Delay(1);
					 for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[11];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}       
            	}
            	else if(k==1 || k==2)
            	{
            		for(j=0;j<100;j++)
                		{
            				IO_REG0 =0xfe00 + LED_tb4[k-1];
                			Delay(1);
                		}
            	}	
            	else if(k==3)
                	{
                		for(j=0;j<100;j++)
                		{
                			IO_REG0=0xfe00 + LED_tb4[1];
            			    Delay(1);
            			    IO_REG0=0xfd00 + LED_tb4[k-1];
							Delay(1); 
                		}
                	}
            	else if(k==4)
            	{
            		for(j=0;j<70;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[2];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[k-1];	
                    		Delay(1); 
            		}
            	}
            	else if(k==5||k==6||k==7||k==8)
            	{
            		for(j=0;j<50;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[2];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[3];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[k-1];
                    		Delay(1); 
            		}
            	}
            	else if(k==9)
            	{
            		for(j=0;j<50;j++)
            		{
                    		IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[2];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[k-1];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}
            	}
            	else if(k==10)
            	{
            		for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[k-1];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}
            	}
            	else
            	{
            		for(j=0;j<50;j++)
            		{
                            IO_REG0 =0xfe00 + LED_tb4[k-1];
                    		Delay(1); 
                    		IO_REG0 =0xfd00 + LED_tb4[9];
                    		Delay(1); 
                    		IO_REG0 =0xfb00 + LED_tb4[8];	
                    		Delay(1); 
                    		IO_REG0 =0xf700 + LED_tb4[7];
                    		Delay(1); 
            		}
            	}
                  
            }		   
		}
//-----------------------------------------------------------------------------//        
        else                 //1關  向右
		{
            io_reg1 =IO_REG1;
		    io_reg1 =io_reg1 | 0xfffd;
		    if(io_reg1 == 0xfffd) // 2開 啟 用
		    {    
                i=(i+1)%21; 
		        if(i==0)   // 全暗
		        {
		            IO_REG2 = 0xffff;
			        Delay(1);
			        for(j=0;j<100;j++)
			        {
            		    IO_REG0 =0xfeff ;
            			IO_REG0 =0xfdff ;
            			IO_REG0 =0xfbff ;
            			IO_REG0 =0xf7ff ;
            			Delay(1);
			        }
		        }
		        else if(i==1)
		        {
        		    IO_REG2 = 0xfeff;
        		    Delay(100); 
		        }
		        else if(i==2)
		        {
        		    IO_REG2 = 0xfcff;
        		    Delay(100); 
		        }
		        else if(i==3)
		        {
            		IO_REG2 = 0xf8ff;
            	    Delay(100); 
		        }
		        else if(i==4)
		        {
            		IO_REG2 = 0xf0ff;
            		Delay(100); 
            	}
		        else if(i==5)
		        {
		            IO_REG2 = 0xe0ff;
		            Delay(100); 
		        }
		        else if(i==6)
		        {
		            IO_REG2 = 0xc0ff;
		            Delay(100); 
		        }
		        else if(i==7)
		        {
		            IO_REG2 = 0x80ff;
		            Delay(100); 
		        }
		        else if(i==8)
		        {
            		IO_REG2 = 0x00ff;
            		Delay(100); 
		        }
		        else if(i==9||i==10)
		        {
		            IO_REG0 =0xfe00 + LED_tb1[i-9];
		            Delay(100); 
		        }
			    else if(i==11)
		        {
		              for(j=0;j<100;j++)
			         {
                			IO_REG0 =0xfe00 + LED_tb1[1];
                			Delay(1);    
                		    IO_REG0 =0xfd00 + LED_tb1[i-9];	
                			Delay(1); 
			        }
			    }
		      else if(i==12)
		      {
		          for(j=0;j<50;j++)
			     {
        		    IO_REG0 =0xfe00 + LED_tb1[1];
        			Delay(1); 
        		    IO_REG0 =0xfd00 + LED_tb1[2];
        			Delay(1); 
        			IO_REG0 =0xfb00 + LED_tb1[i-9];	
        			Delay(1); 
			     }
		      }
		      else if(i==13||i==14||i==15||i==16)
		      {
		          for(j=0;j<50;j++)
			    {
        		    IO_REG0 =0xfe00 + LED_tb1[1];
        		    Delay(1); 
        			IO_REG0 =0xfd00 + LED_tb1[2];
        			Delay(1); 
        			IO_REG0 =0xfb00 + LED_tb1[3];	
        			Delay(1); 
        			IO_REG0 =0xf700 + LED_tb1[i-9];
        			Delay(1); 
			     }
		      }	
		      else if(i==17)
		      {
		          for(j=0;j<50;j++)
			     {
        			IO_REG0 =0xfe00 + LED_tb1[1];
        		    Delay(1); 
        			IO_REG0 =0xfd00 + LED_tb1[2];
        			Delay(1); 
        			IO_REG0 =0xfb00 + LED_tb1[i-9];	
        			Delay(1); 
        			IO_REG0 =0xf700 + LED_tb1[7];
        			Delay(1); 
			     }
		      }
		      else if(i==18)
		      {
		          for(j=0;j<50;j++)
			     {
        		    IO_REG0 =0xfe00 + LED_tb1[1];
        		    Delay(1); 
        			IO_REG0 =0xfd00 + LED_tb1[i-9];
        			Delay(1); 
        			IO_REG0 =0xfb00 + LED_tb1[8];	
        			Delay(1); 
        			IO_REG0 =0xf700 + LED_tb1[7];
        			Delay(1); 
			     }
		      }
		      else 
		      {
        		   for(j=0;j<50;j++)
        		{
        			IO_REG0 =0xfe00 + LED_tb1[i-9];
        		    Delay(1); 
        			IO_REG0 =0xfd00 + LED_tb1[9];
        			Delay(1); 
        			IO_REG0 =0xfb00 + LED_tb1[8];	
        			Delay(1); 
        			IO_REG0 =0xf700 + LED_tb1[7];
        			Delay(1); 
        		}
		      }
		    } 
    		   else    // 2開 不啟 用
    		   {
    		   i=(i+1)%21; 
    		   if(i==0) // 全暗
    		   {
    		   IO_REG2 = 0xffff;
    			Delay(1);
    			for(j=0;j<100;j++)
    			{
    		    IO_REG0 =0xfeff ;
    			IO_REG0 =0xfdff ;
    			IO_REG0 =0xfbff ;
    			IO_REG0 =0xf7ff ;
    			Delay(1);
    			}
    		   }
    		   else if(i==1)
    		   {
    		   IO_REG2 = 0xfeff;
    		   Delay(100); 
    		   }
    		   else if(i==2)
    		   {
    		   IO_REG2 = 0xfcff;
    		   Delay(100); 
    		   }
    		   else if(i==3)
    		   {
    		   IO_REG2 = 0xf8ff;
    		   Delay(100); 
    		   }
    		   else if(i==4)
    		   {
    		   IO_REG2 = 0xf0ff;
    		   Delay(100); 
    		   }
    		   else if(i==5)
    		   {
    		   IO_REG2 = 0xe0ff;
    		   Delay(100); 
    		   }
    		   else if(i==6)
    		   {
    		   IO_REG2 = 0xc0ff;
    		   Delay(100); 
    		   }
    		   else if(i==7)
    		   {
    		   IO_REG2 = 0x80ff;
    		   Delay(100); 
    		   }
    		   else if(i==8)
    		   {
    		   IO_REG2 = 0x00ff;
    		   Delay(100); 
    		   }
    		   else if(i==9||i==10)
    		   {
    		   IO_REG0 =0xfe00 + LED_tb2[i-9];
    		    Delay(100); 
    			}	
    			else if(i==11)
    		   {
    		    for(j=0;j<100;j++)
    			{
    			IO_REG0 =0xfe00 + LED_tb2[1];
    			Delay(1);    
    		    IO_REG0 =0xfd00 + LED_tb2[i-9];	
    			Delay(1); 
    			}
    			}
    		   else if(i==12)
    		   {
    		   for(j=0;j<50;j++)
    			{
    		    IO_REG0 =0xfe00 + LED_tb2[1];
    			Delay(1); 
    		    IO_REG0 =0xfd00 + LED_tb2[2];
    			Delay(1); 
    			IO_REG0 =0xfb00 + LED_tb2[i-9];	
    			Delay(1); 
    			}
    		   }
    		   else if(i==13||i==14||i==15||i==16)
    		   {
    		   for(j=0;j<50;j++)
    			{
    		    IO_REG0 =0xfe00 + LED_tb2[1];
    		    Delay(1); 
    			IO_REG0 =0xfd00 + LED_tb2[2];
    			Delay(1); 
    			IO_REG0 =0xfb00 + LED_tb2[3];	
    			Delay(1); 
    			IO_REG0 =0xf700 + LED_tb2[i-9];
    			Delay(1); 
    			}
    		   }	
    		   else if(i==17)
    		   {
    		    for(j=0;j<50;j++)
    			{
    			IO_REG0 =0xfe00 + LED_tb2[1];
    		    Delay(1); 
    			IO_REG0 =0xfd00 + LED_tb2[2];
    			Delay(1); 
    			IO_REG0 =0xfb00 + LED_tb2[i-9];	
    			Delay(1); 
    			IO_REG0 =0xf700 + LED_tb2[7];
    			Delay(1); 
    			}
    		   }
    		   else if(i==18)
    		   {
    		   for(j=0;j<50;j++)
    			{
    		    IO_REG0 =0xfe00 + LED_tb2[1];
    		    Delay(1); 
    			IO_REG0 =0xfd00 + LED_tb2[i-9];
    			Delay(1); 
    			IO_REG0 =0xfb00 + LED_tb2[8];	
    			Delay(1); 
    			IO_REG0 =0xf700 + LED_tb2[7];
    			Delay(1); 
    			}
    		   }
    		   else 
    		   {
    		   for(j=0;j<50;j++)
    			{
    			IO_REG0 =0xfe00 + LED_tb2[i-9];
    		    Delay(1); 
    			IO_REG0 =0xfd00 + LED_tb2[9];
    			Delay(1); 
    			IO_REG0 =0xfb00 + LED_tb2[8];	
    			Delay(1); 
    			IO_REG0 =0xf700 + LED_tb2[7];
    			Delay(1); 
    			}
    		   }
    		  } 
    		  }
		   
		  
		  
		  
		  }		   
         }        
                
        DisableInterrupt(BIT_GMASK);
}
		   
		  
