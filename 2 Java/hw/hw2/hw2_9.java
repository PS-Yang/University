import java.util.*;
import java.util.Scanner;
public class hw2_9 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		int count=0;
		while(true)
		{

			System.out.print("�п�J�@��Ʀr: ");

    		str=scn.nextLine(); // �N��J����r���w���r���ܼ�str�s��
			if(str.equals("q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //�p��Token��
			 int a []=new int [n];

			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());

             System.out.println("sum="+sum(a));
			}
		}
    }

 	public static int sum(int a[])
    {
      int sum=0;
      for(int i=0;i<a.length;i++)
      	if(a[i]%3==0 && a[i]%2!=0)
      	 sum=sum+a[i];
      return sum;
    }
}
