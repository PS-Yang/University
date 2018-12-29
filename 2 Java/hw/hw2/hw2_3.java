
import java.util.*;
import java.util.Scanner;
public class hw2_3 {

    public static void main(String[] args)
    {
        System.out.println("min(8,5)= "+min(8,5));
		System.out.println("min(8,2,9)= "+min(8,2,9));
    }
    public static int min(int a,int b)
    {
      if(a<b)
    	return a;
      else
      	return b;
    }
    public static int min(int a,int b,int c)
    {
     if(a<=b && a<=c)
     	return a;
     else if(b<=a && b<=c)
    	return b;
     else
     	return c;
    }
}
