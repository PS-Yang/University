class CCustomer extends Thread
{
  public String str;
  private static int sum=10000;
  public CCustomer(String s)
  {
  	str=s;
  }
  public void run()
  {
    for(int i=1;i<=8;i++)
     sub((int)(20*Math.random())*100);
  }

  public synchronized void sub(int n)
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
  	   System.out.println(str+"���"+n+"��, �ѤU"+sum+"��");
     }
    else
    System.out.println(str+"���"+n+"��, �l�B����!!");
  }
}

public class hw6_4_n {

    public static void main(String args[])
    {
     CCustomer c1=new CCustomer("���_���l��");
     CCustomer c2=new CCustomer("���v�j�l��");
     c1.start();
     c2.start();
    }


}