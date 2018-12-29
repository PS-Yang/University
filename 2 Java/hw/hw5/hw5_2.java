class CShape // 父類別CShape
 {
    public double area()
   {
     return 0.0;
   }
 }

class CCircle extends CShape
{
	private double r;
	private double PI=3.14;
	public CCircle(double ra)
	{
		r=ra;
	}
	public double area()
	{
		return r*r*PI;
	}
}

class CSquare extends CShape
{
	private double r;
	public CSquare(double ra)
	{
		r=ra;
	}
	public double area()
	{
		return r*r;
	}
}

class CTriangle extends CShape
{
	private double a,b;
	public CTriangle(double ra,double rb)
	{
		a=ra;
		b=rb;
	}
	public double area()
	{
		return a*b/2;
	}
}

public class hw5_2
{
  public static void main (String args[])
  {
    CShape shp[]=new CShape[6];
    shp[0]=new CCircle(2.0);
    shp[1]=new CCircle(3.0);
    shp[2]=new CSquare(4.0);
    shp[3]=new CSquare(5.0);
    shp[4]=new CTriangle(3.0,3.0);
    shp[5]=new CTriangle(5.0,4.0);
    for(int i=0;i<6;i++)
    System.out.println("面積"+(i+1)+" = "+shp[i].area());
    largest(shp);
  }
  public static void largest(CShape shp[] )
  {
  	double max;
  	max=shp[0].area();
  	for(int i=0;i<6;i++)
  		if(max<shp[i].area())
  			max=shp[i].area();

    System.out.println("面積最大 = "+max);
  }
}