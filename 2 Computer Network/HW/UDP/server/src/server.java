// UDP Server 程式
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class server
{
	public static void main(String args[]) throws Exception
	{
		byte buffer[]=new byte[10];      //buffer是10byte的陣列
		byte buffer3[]=new byte[10];     //
		byte buffer5[]=new byte[10];     //
		byte buffer6[]=new byte[10];
		Scanner scn=new Scanner(System.in);
		String msg,AB,str,str3,nums;
		int num_count=0;
		int num_count2=0;
		int num,ni;
		int a[]=new int[10];
		int n[]=new int[10];
		int portNo=5555;     //設port =>server端
		int port_c = 5500;   //設port =>client端
		System.out.println("Server端開始接受連線請求!");  //print出的文字訊息

		DatagramPacket packet = new DatagramPacket (buffer,buffer.length);  //建立Datagram packet資料封包,限制packet值和長度大小
		DatagramSocket socket= new DatagramSocket(portNo);  //建立socket 需要設port=>Server端
		socket.receive(packet);   //接收封包
		String addr_s =new String(buffer,0,packet.getLength());  //將訊息轉為字串 =>Server IP

		InetAddress addr_c = packet.getAddress();//得到packet的來源IP =>Client IP



		System.out.println("Server端IP:"+addr_s+"Port號"+portNo);  //print  ServerIP Port
		System.out.println("Client端IP:"+addr_c.getHostAddress()+"Port號"+port_c);  //print Client IP Port

		int cLength=addr_c.getHostAddress().length();     //將client IP長度放到cLength
		byte buffer2[]=new byte[cLength];
		buffer2=addr_c.getHostAddress().getBytes();
        DatagramPacket packet2= new DatagramPacket(buffer2,cLength,addr_c,port_c);    //訊息封包(值,大小,Clinet IP,port)
        socket.send(packet2);    //送出packet封包訊息

		while(true)
		{
		 DatagramPacket packet6= new DatagramPacket (buffer6,buffer6.length);  //建立Datagram packet資料封包,限制packet值和長度大小
		 socket.receive(packet6);   //接收封包
	     nums=new String(buffer6,0,packet6.getLength());  //將訊息轉為字串
	     ni=Integer.parseInt(nums);
		 System.out.print("要自己輸入答案請按1  要亂數隨機產生請按2:");
	 	 /*--------------------自己輸入答案--------------------------*/
		 str=scn.nextLine();
		 if(str.equals("1")) //輸入1時自己輸入答案
		 {
			 do
			 {
			 System.out.print("請輸入正確解答("+ni+"位數):");
			 str3=scn.nextLine();
			 int ai=Integer.parseInt(str3);
			 num_count=0;
			 for(int i=ni-1;i>=0;i--)
			  {
			  a[i]=ai%10;
			  ai=ai/10;
			  }
			  for(int j=0;j<ni;j++)
				   for(int i=0;i<ni;i++)
				    if( (a[i]==a[j] &&i!=j) || a[0]==0)
				     num_count++;   //判斷值是否相同
			 }while(num_count!=0);

			 System.out.print("你所輸入的答案:");
			 for(int i=0;i<ni;i++)
			 System.out.print(a[i]);
		 }
		/*--------------------亂數產生答案--------------------------*/
		 else
	 	 {
		  do
		  {
			  num_count2=0;

			  for(int i=0;i<ni;i++)
			  a[i]=(int)(Math.random()*10);//0~9

			  for(int j=0;j<ni;j++)
				   for(int i=0;i<ni;i++)
				    if((a[i]==a[j]&&i!=j) || a[0]==0)
				     num_count2++;   //判斷值是否相同
		  }while(num_count2!=0);
	    	System.out.println("亂數產生答案:");
	    	for(int i=0;i<ni;i++)
			System.out.print(a[i]);
		}
		/*----------------------------------------------------------*/


	       while(true)
		   {
			DatagramPacket packet3= new DatagramPacket (buffer3,buffer3.length);  //建立Datagram packet資料封包,限制packet值和長度大小
			socket.receive(packet3);   //接收封包
			msg=new String(buffer3,0,packet3.getLength());  //將訊息轉為字串
			num=Integer.parseInt(msg);
			for(int i=ni-1;i>=0;i--)
			{
			  n[i]=num%10;
			  num=num/10;
			}
			int A=0,B=0;

			for(int i=0;i<ni;i++)
			{
				if(a[i]==n[i]) //位置相同A++
				{
					A++;
				}
				for(int j=0;j<ni;j++)
				{
				 if(a[i]==n[j]&&i!=j)//位置不同但數值相同B++
				 {
					 B++;
				 }
				}
			}

		       System.out.println("收到下面的訊息 : " + msg);   //print出的文字訊息
			   AB=new String(A+"A"+B+"B");   //把幾A幾B的值放到字串AB裡
		       System.out.println(AB);
			   int ABLength=AB.length();     //將AB長度大小放到ABLength
			   byte buffer4[]=new byte[ABLength];
			   buffer4=AB.getBytes();
               DatagramPacket packet4= new DatagramPacket(buffer4,ABLength,addr_c,port_c);    //訊息封包(值(xAxB),大小,Client IP,port)
			   socket.send(packet4);    //送出packet封包訊息


			   if(A==ni) //全對時
			   {
				DatagramPacket packet5 = new DatagramPacket (buffer5,buffer5.length);  //建立Datagram packet資料封包,限制packet值和長度大小
				socket.receive(packet5);   //接收封包
				str=new String(buffer5,0,packet5.getLength());  //將訊息轉為字串
				break;//跳出迴圈
			  }
		 }
		 if(str.equals("N")||str.equals("n")) //輸入(n/N)時結束並且關閉socket
		 {
		         socket.close();
				 break;  //跳出最外面的while迴圈
		 }
	   }
    }
  }