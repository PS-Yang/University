import java.util.*;
import java.util.Scanner;
public class test1 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		while(true)
		{

			System.out.print("��J: ");

    		str=scn.nextLine(); // �N��J����r���w���r���ܼ�str�s��
			if(str.equals("q"))
       			break;
			else
			{
			 StringBuffer st2=new StringBuffer();
			 str=str.append(str);

			 if(str.equals(st2.reverse()))
			 System.out.println(str+"�O�j��");
	         System.out.println(str);
		}
    }

    }
}
