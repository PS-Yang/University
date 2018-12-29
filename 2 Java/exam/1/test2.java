import java.util.*;
import java.util.Scanner;
public class test2 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		int count=0;
		while(true)
		{

			System.out.print("輸入n值(1~200)(輸入q離開): ");

    		str=scn.nextLine(); // 將輸入的文字指定給字串變數str存放
			if(str.equals("q")||str.equals("Q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //計算Token數
			 if(n!=1)
			 {
			 	System.out.println("只能輸入一個數值或q!");
			 	continue;
			 }
			 int a []=new int [n];

			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());
             if(a[0]>200||a[0]<1)
             {
                System.out.println("數值介於1~200!!");
			 	continue;
             }

             double sum=0;

             for(int i=0;i<=a[0];i++)
             sum=sum+count(i);

             System.out.println("g(x)="+sum);

			}
		}

    }
      public static double count(int num)
     {
    	int n=num;

    	if(n==0)
    		return 1;
    	else
    		return (double) (count(n-1)*2)/n;
     }
}
