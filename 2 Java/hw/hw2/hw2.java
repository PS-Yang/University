import java.util.Scanner;
public class hw2 {

 public static void main(String[] args)
    {
      Scanner scn=new Scanner(System.in);
      String str;
      String q=new String("q");
      int count2=0,count4=0,count6=0,count8=0;
      while(true)
      {

       System.out.print("�п�J�r��:(�p�G��Jq�h���}�{��)");
       str=scn.next();

       if(str.equals(q))
       	break;
       else
       {
          for(int i=0 ; i<str.length() ; i++)
          {
            switch(str.charAt(i))
            {
             case '2':
				count2++;
				break;
			 case '4':
				count4++;
				break;
			 case '6':
				count6++;
				break;
			 case '8':
				count8++;
				break;
            }
          }
          System.out.println("�Ʀr2�X�{"+count2+"��!!");
          System.out.println("�Ʀr4�X�{"+count4+"��!!");
          System.out.println("�Ʀr6�X�{"+count6+"��!!");
          System.out.println("�Ʀr8�X�{"+count8+"��!!");

          count2=0;count4=0;count6=0;count8=0;
       }

      }


    }
}