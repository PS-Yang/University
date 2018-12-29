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
       System.out.print("請輸入三個點的座標(輸入q離開):");
       str=scn.nextLine(); // 將輸入的文字指定給字串變數str存放
       if(str.equals("q")|| str.equals("Q"))
       break;
       else
       {
       	StringTokenizer st = new StringTokenizer(str);
        n=st.countTokens(); //計算Token數
        if(n!=6)      //確認是否輸入三個點的座標
        {
         System.out.println("請輸入三個點的X座標與Y座標!!");
         continue;
        }
	    int num[]=new int [n];
		for(int i=0;i<n;i++)
	     num[i]=Integer.parseInt(st.nextToken());

	    Point p1=new Point(num[0],num[1]);
	    Point p2=new Point(num[2],num[3]);
	    Point p3=new Point(num[4],num[5]);

        System.out.println("與原點距離:"+p1.distance()+" "+p2.distance()+" "+p3.distance());
        System.out.println("任兩點距離:"+p1.distance(p2)+" "+p1.distance(p3)+" "+p2.distance(p3));

        if( p1.distance(p2)>=p1.distance(p3) && p1.distance(p2)>=p2.distance(p3)) //判斷哪兩點距離比較短
           System.out.println("距離最遠的兩個點:A B!!");
        else if( p1.distance(p3)>=p1.distance(p2) && p1.distance(p3)>=p2.distance(p3))
           System.out.println("距離最遠的兩個點:A C!!");
        else
           System.out.println("距離最遠的兩個點:B C!!");
       }
     }
    }
}