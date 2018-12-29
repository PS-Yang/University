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

       System.out.print("叫块﹃:(狦块q玥瞒秨祘Α)");
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
          System.out.println("计2瞷"+count2+"Ω!!");
          System.out.println("计4瞷"+count4+"Ω!!");
          System.out.println("计6瞷"+count6+"Ω!!");
          System.out.println("计8瞷"+count8+"Ω!!");

          count2=0;count4=0;count6=0;count8=0;
       }

      }


    }
}