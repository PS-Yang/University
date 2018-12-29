class CBank
{
  private static int sum=10000;
  public synchronized  static void sub(int n,String s)
  {

  	  try
  	  {
  	    Thread.sleep((int)(2000*Math.random()));
  	  }
  	  catch(InterruptedException e){}
  	 if(sum>=n)
  	 {
  	   int temp=sum;
  	   temp=temp-n;
  	   sum=temp;
  	   System.out.println(s+"領取"+n+"元, 剩下"+sum+"元");
     }
    else
    System.out.println(s+"領取"+n+"元, 餘額不足!!");
  }
}
class CCustomer extends Thread
{
  public String str;
  public CCustomer(String s)
  {
  	str=s;
  }
  public void run()
  {
    for(int i=1;i<=8;i++)
     CBank.sub((int)(20*Math.random())*100,str);
  }
}


public class hw6_4 {

    public static void main(String args[])
    {
     CCustomer c1=new CCustomer("光復路郵局");
     CCustomer c2=new CCustomer("彰師大郵局");
     c1.start();
     c2.start();
    }


}