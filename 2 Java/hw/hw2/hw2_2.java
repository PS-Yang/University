import java.util.*;
import java.util.Scanner;
public class hw2_2 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		while(true)
		{

			System.out.print("�п�J�T���Ϊ��T���: ");

    		str=scn.nextLine(); // �N��J����r���w���r���ܼ�str�s��
			if(str.equals("q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //�p��Token��
			 if(n>3)  //�P�_�O�_���T�ӼƦr
			 {
			 	System.out.println("�u���J�T�ӼƦr!!!");
			 	continue;
			 }
			 int a []=new int [n];

			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());

			  if(a[0]==0)  //�P�_����O�_���O0��
             {
               System.out.println("����n>1 !!!");
               continue;
             }
			  for(int i=0;i<n;i++)
			  {
			  	 for(int j=i+1;j<n;j++)
			  	 {
			 	   int temp;
			 	   if(a[i]>a[j])
			 	   {
			 	     temp=a[i];
			 	     a[i]=a[j];
			 	     a[j]=temp;
			 	   }
			 	 }
			  }
              if( (a[0]+a[1]) <a[2])
   			  System.out.println("����Φ��T����!!!");
   			  else
   			  {
   			  	int ab=a[0]*a[0]+a[1]*a[1];

   			  	if(ab==a[2]*a[2])
   			  	 System.out.println("�����T����(right triangle)!!");
   			  	if(ab>a[2]*a[2])
   			  	 System.out.println("�w���T����(acute triangle)!!");
   			  	if(ab<a[2]*a[2])
   			  	 System.out.println("�U���T����(obtuse triangle)!!");
   			  }
			}
		}
    }
}
