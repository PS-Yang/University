import java.util.*;
import java.io.*;
public class hw2_1 {

    public static void main(String[] args) throws IOException
    {
    	String str;
    	BufferedReader buf;
		buf=new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{

			System.out.print("請輸入一串整數: ");

    		str=buf.readLine(); // 將輸入的文字指定給字串變數str存放
			if(str.equals("q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //計算Token數
			 int a []=new int [n];

			 System.out.print("排序前的數字");
			 for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());

			 int min=a[0];
			 int max=a[0];
        	 for(int i=0;i<n;i++)
        	 {
        	  System.out.print(a[i]+"  ");
        	 	if(a[i]>max)
        		 	max=a[i];
             	if(a[i]<min)
            	 	 min=a[i];
         	 }
			 System.out.print("\n最大值="+max);
			 System.out.println("最小值="+min);
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
			 System.out.print("排序後的數字");
			 for(int i=0;i<n;i++)
        	  System.out.print(a[i]+"  ");
   			System.out.println();
			}
		}
    }
}
