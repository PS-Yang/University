class CTriangle
{
  private int base,height;
  private String color;
  public void setB(int b)
  {
  	base=b;
  }
  public void setH(int h)
  {
  	height=h;
  }
  public void setColor(String c)
  {
  	color=c;
  }
  public CTriangle()
  {
  	base=10;
  	height=5;
  	color="blue";
  }
  public CTriangle(int b,int h,String c)
  {
  	setB(b);
  	setH(h);
  	setColor(c);
  }
  public void show()
  {
  	System.out.println("Color="+color);
  	System.out.println("base="+base+" ,height="+height+"\n");
  }
}





public class hw4_1 {

    public static void main(String[] args)
    {
    	CTriangle ct1=new CTriangle();
    	CTriangle ct2=new CTriangle(30,10,"Red");
    	ct1.show();
    	ct2.show();
    }


}