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

			System.out.print("�п�J�@����: ");

    		str=buf.readLine(); // �N��J����r���w���r���ܼ�str�s��
			if(str.equals("q"))
       			break;
			else
			{
			 StringTokenizer st = new StringTokenizer(str);

			 int n=st.countTokens(); //�p��Token��
			 int a []=new int [n];

			 System.out.print("�Ƨǫe���Ʀr");
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
			 System.out.print("\n�̤j��="+max);
			 System.out.println("�̤p��="+min);
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
			 System.out.print("�Ƨǫ᪺�Ʀr");
			 for(int i=0;i<n;i++)
        	  System.out.print(a[i]+"  ");
   			System.out.println();
			}
		}
    }
}
