import java.util.*;
import java.util.Scanner;
class Point
{
  private int x;
  private int y;

  public Point(int a,int b)
  {
    x=a;
    y=b;
  }
  public double distance()
  {
  	return Math.sqrt(x*x+y*y);
  }
  public double distance(Point p)
  {
  	return Math.sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
  }
}
public class hw4_3 {

    public static void main(String[] args)
    {
     Scanner scn=new Scanner(System.in);
     String str;
     int n;
     double max=0;
     while(true)
     {
       System.out.print("�п�J�T���I���y��(��Jq���}):");
       str=scn.nextLine(); // �N��J����r���w���r���ܼ�str�s��
       if(str.equals("q")|| str.equals("Q"))
       break;
       else
       {
       	StringTokenizer st = new StringTokenizer(str);
        n=st.countTokens(); //�p��Token��
        if(n!=6)      //�T�{�O�_��J�T���I���y��
        {
         System.out.println("�п�J�T���I��X�y�лPY�y��!!");
         continue;
        }
	    int num[]=new int [n];
		for(int i=0;i<n;i++)
	     num[i]=Integer.parseInt(st.nextToken());

	    Point p1=new Point(num[0],num[1]);
	    Point p2=new Point(num[2],num[3]);
	    Point p3=new Point(num[4],num[5]);

        System.out.println("�P���I�Z��:"+p1.distance()+" "+p2.distance()+" "+p3.distance());
        System.out.println("�����I�Z��:"+p1.distance(p2)+" "+p1.distance(p3)+" "+p2.distance(p3));

        if( p1.distance(p2)>=p1.distance(p3) && p1.distance(p2)>=p2.distance(p3)) //�P�_�����I�Z������u
           System.out.println("�Z���̻�������I:A B!!");
        else if( p1.distance(p3)>=p1.distance(p2) && p1.distance(p3)>=p2.distance(p3))
           System.out.println("�Z���̻�������I:A C!!");
        else
           System.out.println("�Z���̻�������I:B C!!");
       }
     }
    }
}