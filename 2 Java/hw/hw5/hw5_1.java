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

public class hw5_1
{
  public static void main (String args[])
  {
    CCircle cir1=new CCircle(2.0);
    CCircle cir2=new CCircle(3.0);
    CSquare squ1=new CSquare(4.0);
    CSquare squ2=new CSquare(5.0);
    CTriangle tri1=new CTriangle(3.0,3.0);
    CTriangle tri2=new CTriangle(5.0,4.0);
    System.out.println("面積1 = "+cir1.area());
    System.out.println("面積2 = "+cir2.area());
    System.out.println("面積3 = "+squ1.area());
    System.out.println("面積4 = "+squ2.area());
    System.out.println("面積5 = "+tri1.area());
    System.out.println("面積6 = "+tri2.area());

    largest(cir1.area(),cir2.area(),squ1.area(),squ2.area(),tri1.area(),tri2.area());
  }
  public static void largest(double a,double b,double c,double d,double e,double f)
  {
  	double num[]=new double [6];
  	double max;
  	num[0]=a;
  	num[1]=b;
  	num[2]=c;
  	num[3]=d;
  	num[4]=e;
  	num[5]=f;
  	max=num[0];
  	for(int i=0;i<6;i++)
  		if(max<num[i])
  			max=num[i];

    System.out.println("面積最大 = "+max);
  }
}