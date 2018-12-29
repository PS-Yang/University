import java.util.*;
import java.util.Scanner;
public class test1 {

    public static void main(String[] args)
    {
		Scanner scn=new Scanner(System.in);
		String str;
		while(true)
		{

			System.out.print("輸入: ");

    		str=scn.nextLine(); // 將輸入的文字指定給字串變數str存放
			if(str.equals("q"))
       			break;
			else
			{
			 StringBuffer st2=new StringBuffer();
			 str=str.append(str);

			 if(str.equals(st2.reverse()))
			 System.out.println(str+"是迴文");
	         System.out.println(str);
		}
    }

    }
}
