import java.util.*;
import java.util.Scanner;
public class hw2_2 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		while(true)
		{

			System.out.print("請輸入三角形的三邊長: ");

    		str=scn.nextLine(); // 將輸入的文字指定給字串變數str存放
			if(str.equals("q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //計算Token數
			 if(n>3)  //判斷是否為三個數字
			 {
			 	System.out.println("只能輸入三個數字!!!");
			 	continue;
			 }
			 int a []=new int [n];

			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());

			  if(a[0]==0)  //判斷邊長是否有是0的
             {
               System.out.println("邊長要>1 !!!");
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
   			  System.out.println("不能形成三角形!!!");
   			  else
   			  {
   			  	int ab=a[0]*a[0]+a[1]*a[1];

   			  	if(ab==a[2]*a[2])
   			  	 System.out.println("直角三角形(right triangle)!!");
   			  	if(ab>a[2]*a[2])
   			  	 System.out.println("鈍角三角形(acute triangle)!!");
   			  	if(ab<a[2]*a[2])
   			  	 System.out.println("銳角三角形(obtuse triangle)!!");
   			  }
			}
		}
    }
}
