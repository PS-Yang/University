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

           System.out.println("�п�J�d�򪺳̤j�ȭn��h��");
    	   max=scn.next();


    	   if( max.equals(str1))
    		 break;
    	   else
           {
        	 System.out.println("�i�H�Q9�M7�㰣���Ʀr��:");
             int n = Integer.parseInt(max); //�N�r���ഫ�����

        	 for(int i=1;i<=n;i++)
        	 {
         		if(i%7==0 && i%9==0)
         		{
            		System.out.println(+i);
            		count++;
         		}
        	}
            System.out.println("�`�@��"+count+"�ӼƦr");
            count=0;
           }
    	}
    }
}