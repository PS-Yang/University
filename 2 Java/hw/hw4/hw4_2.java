class CSphere
{
  private int x; // ��ߪ�x �y��
  private int y; // ��ߪ�y �y��
  private int z; // ��ߪ�z �y��
  private double radius; // ��y���b�|
  private double d;

  public CSphere(int a,int b,int c,double r)
  {
  	x=a;
  	y=b;
  	z=c;
  	radius=r;
  }
  public double distance(CSphere cs)
  {
   d=Math.sqrt( (this.x-cs.x)*(this.x-cs.x)+(this.y-cs.y)*(this.y-cs.y)+(this.z-cs.z)*(this.z-cs.z) );
   return d;
  }
  public void isIntersect(CSphere cs)
  {
  	if (d<=(this.radius+cs.radius))
     System.out.println("2�y���IĲ");
    else
     System.out.println("2�y�L�IĲ");
  }
  public void show()
  {
   System.out.println("x="+x+", y="+y+", z="+z+", radius="+(int)radius);
  }
}


public class hw4_2 {

    public static void main(String[] args)
    {
      CSphere cs1=new CSphere(7,4,5,2);
      CSphere cs2=new CSphere(6,2,8,3);
      cs1.show();
      cs2.show();
      System.out.println("2�y��ߪ��Z�� = "+cs1.distance(cs2));
      cs1.isIntersect(cs2);
    }


}