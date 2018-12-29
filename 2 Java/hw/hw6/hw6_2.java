import java.io.*;
import java.util.*;
public class hw6_2 {

    public static void main (String args[]) throws IOException
    {
      String str;

      FileInputStream fi=new FileInputStream("C:\\file_practice_2.txt");

      FileOutputStream fo=new FileOutputStream("C:\\out2.txt");

      byte ba[]=new byte[fi.available()];
      fi.read(ba);


      int n=ba.length;
      int count=0;
      System.out.println(n);

      for(int i=0;i<n;i++)
      {
       if(ba[i]== 't' && ba[i+1]=='h' && ba[i+2]=='e')
       {
        ba[i]='T';
        ba[i+1]='H';
        ba[i+2]='E';
        count++;
       }
      }
      System.out.println(count);
      fo.write(ba);

      fo.close();
      fi.close();
    }
}