// UDP 客戶端的程式
import java.io.*;
import java.net.*;
import java.util.Scanner;
public class client
{
	public static void main(String args[]) throws Exception
	{
		int portNo =5555;  //設port => server 端
		int port_c =5500;  //設port => client 端
		int count=0,ni;       //記算猜的數字
		double time_s=0;   //Start time

		byte buffer2[]=new byte[10];      //buffer是10byte的陣列
		byte buffer4[]=new byte[10];      //

		String clientIP,str,num;
		Scanner scn=new Scanner(System.in);

		System.out.print("Please input the IP address of destination :");  ////print出的文字訊息
		BufferedReader uip= new BufferedReader(new InputStreamReader(System.in));    //輸入到buffer的字串存到UIP中,並讀出UIP中buffer的內容
		String ServerIP=uip.readLine();  //將UIP內容讀到ServerIP
		InetAddress addr=InetAddress.getByName(ServerIP);  //抓出ServerIP位址
		int aLength=ServerIP.length();     //將addr放到aLength
		byte buffer[]=new byte[aLength];
		buffer=ServerIP.getBytes();
        DatagramPacket packet= new DatagramPacket(buffer,aLength,addr,portNo);//訊息封包(值,大小,Server 位址,Server port)
		DatagramSocket socket=new DatagramSocket(port_c);  //建立socket
		socket.send(packet);    //送出packet封包訊息



		DatagramPacket packet2 = new DatagramPacket ( buffer2, buffer2.length );  //建立Datagram packet資料封包,限制packet值和長度大小

		socket.receive(packet2);   //接收封包
		clientIP =new String(buffer2,0,packet.getLength());  //將訊息轉為字串 =>Server IP


			while (true)
		   {    // 一直回傳新訊息

            do{
			System.out.print("ClentIP:"+clientIP+">>請輸入你要猜幾個數字的(1~9):");
			num=scn.nextLine();
			ni=Integer.parseInt(num);
			}while( ni>=10 || ni<=0);

			int nLength=num.length();     // num長度大小放到mLength
			byte buffer6[]=new byte[nLength];
			buffer6=num.getBytes();
            DatagramPacket packet6= new DatagramPacket(buffer6,nLength,addr,portNo);    //訊息封包(值,大小,Server位址,Server port)
            socket.send(packet6); //把num放packet6傳送

			 while(true)
			 {
			  if(count==0)//當count=0 時 設定初始時間
			  time_s=System.currentTimeMillis();

		      System.out.print("ClentIP:"+clientIP+">>請輸入你要猜的字串:");
		   	  String msg=uip.readLine();    //讀UIP中的訊息
			  count++;                      //每猜1次次數+1
			  int mLength=msg.length();     //將msg(數字)長度大小放到mLength
			  byte buffer3[]=new byte[mLength];
			  buffer3=msg.getBytes();
              DatagramPacket packet3= new DatagramPacket(buffer3,mLength,addr,portNo);    //訊息封包(值,大小,Server位址,Server port)
              socket.send(packet3);    //送出packet封包訊息

		      DatagramPacket packet4= new DatagramPacket (buffer4,buffer4.length);  //建立Datagram packet資料封包,限制packet值和長度大小
			  socket.receive(packet4);   //接收封包

			  String AB=new String(buffer4,0,packet4.getLength());  //將訊息轉為字串
			  System.out.println("你所猜的結果是"+AB);    //print xAxB
			  if(AB.equals(ni+"A0B"))              //全部答對時
			  {
		         double time_e=System.currentTimeMillis();
			     double time_total=(time_e-time_s)/1000;
			     System.out.println("恭喜猜對了!!");
			     System.out.println("共猜了"+count+"次");//print次數
			 	 System.out.println("花費" +time_total+"秒");//print 時間
			 	 count=0;		 //次數歸0
		     	 System.out.print("是否繼續猜?<y/n>");
			 	 str=scn.nextLine();
			 	 int sLength=str.length();     //將str長度大小放到sLength
			 	 byte buffer5[]=new byte[sLength];
			 	 buffer5=str.getBytes();
	         	 DatagramPacket packet5= new DatagramPacket(buffer5,sLength,addr,portNo);    //訊息封包(值,大小,位址,port)
	         	 socket.send(packet5);    //送出packet封包訊息
	             break;    //猜對跳出迴圈
			 }
            }
             if(str.equals("N")||str.equals("n")) //輸入(n/N)時結束並且關閉socket
			 {
			 socket.close(); 
			 break; //跳出最外面的while迴圈
			 }
		   }
  }
}
