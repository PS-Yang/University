class CSphere
{
  private int x; // ��ߪ�x �y��
  private int y; // ��ߪ�y �y��
  private int z; // ��ߪ�z �y��
  private int radius; // ��y���b�|
  private double pi=3.14;
  void setLocation(int a,int b,int c)
  {
  	x=a;
  	y=b;
  	z=c;
  }
  void setRadius(int r)
  {
  	radius=r;
  }
  double surfaceArea()
  {
    return 4*pi*radius*radius;
  }
  double volume()
  {
  	return (4*pi*radius*radius*radius)/3;
  }
  void showCenter()
  {
  	System.out.println("x="+x+",y="+y+",z="+z);
  }
}


public class hw3 {

    public static void main(String[] args)
    {
      CSphere csp1=new CSphere();
      csp1.setLocation(3,4,5);
      csp1.setRadius(2);
      csp1.showCenter();
      System.out.println("surface area="+csp1.surfaceArea());
      System.out.println("volume="+csp1.volume());
    }


}