import java.util.*;
import java.util.Scanner;
class CNumber
{
   int num ;
   public CNumber(int n)
   {
      num=n;
   }
   public boolean prime()
   {
   	  int flag=1;
      for(int i=2;i<num;i++)
		if(num%i==0)
		{
			flag=0;
			break;
		}
	  if (flag==1)return true;
	  else return false;
   }
}
public class test3 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		int count=0;
		while(true)
		{
			System.out.print("(���}�Ы�q)    ��J: ");

    		str=scn.nextLine(); // �N��J����r���w���r���ܼ�str�s��
			if(str.equals("q")||str.equals("Q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //�p��Token��
			 if(n!=2)
			 {
			 	System.out.println("�u���J��Ӽƭȩ�q!");
			 	continue;
			 }
			 int a []=new int [n];

			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());
             if(a[1]<a[0])
             {
                System.out.println("�᭱���ƭȭn����j!!");
			 	continue;
             }
             if( a[0]>10000 || a[1]>10000 || a[0]<=0 || a[1]<=0)
             {
                System.out.println("�ƭȤ���1~10000!!");
			 	continue;
             }
             int time=0;
             for(int i=a[0];i<=a[1];i++)
             {
             	CNumber c1=new CNumber(i);
                CNumber c2=new CNumber(i+4);
             	if(c1.prime() && c2.prime())
             	{
             	 System.out.print("("+i+","+(i+4)+")");
             	 time++;
             	}
             }
             System.out.println("�@"+time+"��");
             time=0;
			}
		}

    }
}
