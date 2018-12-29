import java.io.*;
import java.util.*;
public class hw6_1 {

    public static void main (String args[]) throws IOException
    {
      String str;

      FileReader fr=new FileReader("C:\\file_practice.txt");
      BufferedReader bfr=new BufferedReader(fr);

      FileWriter fw=new FileWriter("C:\\out.txt");
      BufferedWriter bfw=new BufferedWriter(fw);

      while((str=bfr.readLine())!=null)
      {
      	StringTokenizer st = new StringTokenizer(str);
		int n=st.countTokens(); //≠p∫‚Tokenº∆
	    int a []=new int [n];
        int sum=0;
        for(int i=0;i<n;i++)
			  a[i]=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++)
        	sum=sum+a[i];

        bfw.write( Double.toString( (double)sum/n) );
        bfw.newLine();
      }
       bfw.flush();
       fw.close();
       fr.close();
    }
}