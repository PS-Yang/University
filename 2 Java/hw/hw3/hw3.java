class CSphere
{
  private int x; // 圓心的x 座標
  private int y; // 圓心的y 座標
  private int z; // 圓心的z 座標
  private int radius; // 圓球的半徑
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