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

			System.out.print("��Jn��(1~200)(��Jq���}): ");

    		str=scn.nextLine(); // �N��J����r���w���r���ܼ�str�s��
			if(str.equals("q")||str.equals("Q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //�p��Token��
			 if(n!=1)
			 {
			 	System.out.println("�u���J�@�Ӽƭȩ�q!");
			 	continue;
			 }
			 int a []=new int [n];

			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());
             if(a[0]>200||a[0]<1)
             {
                System.out.println("�ƭȤ���1~200!!");
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
