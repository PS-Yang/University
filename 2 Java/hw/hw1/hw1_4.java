import java.util.Scanner;
public class hw1_4 {

    public static void main (String args[])
    {
    	Scanner scn=new Scanner(System.in);
    	int count=0;
    	String max;
        String str1=new String("q");

        while(true)
        {

           System.out.println("請輸入範圍的最大值要到多少");
    	   max=scn.next();


    	   if( max.equals(str1))
    		 break;
    	   else
           {
        	 System.out.println("可以被9和7整除的數字有:");
             int n = Integer.parseInt(max); //將字串轉換為整數

        	 for(int i=1;i<=n;i++)
        	 {
         		if(i%7==0 && i%9==0)
         		{
            		System.out.println(+i);
            		count++;
         		}
        	}
            System.out.println("總共有"+count+"個數字");
            count=0;
           }
    	}
    }
}