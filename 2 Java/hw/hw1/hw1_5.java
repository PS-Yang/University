import java.util.Scanner;

public class hw1_5 {

    public static void main(String args[])
    {
    	Scanner scn=new Scanner(System.in);
		String n;
		String str=new String("q");
		int N=0,sum=0;

        while(true)
        {

         do{

          System.out.print("�п�J�����N����:");
          n=scn.next();

          if(n.equals(str))
         	break;

          N = Integer.parseInt(n);
    	}while(N<1);

          if(n.equals(str))
         	break;
          else
          {

           for(int i=1 ; i<=N ; i++ )
        	 sum=sum+( (1*i)*(3*i)*(5*i) );

           System.out.println("�ǦCF���`�M="+sum);
           sum=0;
          }
        }

    }
}