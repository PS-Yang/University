// UDP �Ȥ�ݪ��{��
import java.io.*;
import java.net.*;
import java.util.Scanner;
public class client
{
	public static void main(String args[]) throws Exception
	{
		int portNo =5555;  //�]port => server ��
		int port_c =5500;  //�]port => client ��
		int count=0,ni;       //�O��q���Ʀr
		double time_s=0;   //Start time

		byte buffer2[]=new byte[10];      //buffer�O10byte���}�C
		byte buffer4[]=new byte[10];      //

		String clientIP,str,num;
		Scanner scn=new Scanner(System.in);

		System.out.print("Please input the IP address of destination :");  ////print�X����r�T��
		BufferedReader uip= new BufferedReader(new InputStreamReader(System.in));    //��J��buffer���r��s��UIP��,��Ū�XUIP��buffer�����e
		String ServerIP=uip.readLine();  //�NUIP���eŪ��ServerIP
		InetAddress addr=InetAddress.getByName(ServerIP);  //��XServerIP��}
		int aLength=ServerIP.length();     //�Naddr���aLength
		byte buffer[]=new byte[aLength];
		buffer=ServerIP.getBytes();
        DatagramPacket packet= new DatagramPacket(buffer,aLength,addr,portNo);//�T���ʥ](��,�j�p,Server ��},Server port)
		DatagramSocket socket=new DatagramSocket(port_c);  //�إ�socket
		socket.send(packet);    //�e�Xpacket�ʥ]�T��



		DatagramPacket packet2 = new DatagramPacket ( buffer2, buffer2.length );  //�إ�Datagram packet��ƫʥ],����packet�ȩM���פj�p

		socket.receive(packet2);   //�����ʥ]
		clientIP =new String(buffer2,0,packet.getLength());  //�N�T���ର�r�� =>Server IP


			while (true)
		   {    // �@���^�Ƿs�T��

            do{
			System.out.print("ClentIP:"+clientIP+">>�п�J�A�n�q�X�ӼƦr��(1~9):");
			num=scn.nextLine();
			ni=Integer.parseInt(num);
			}while( ni>=10 || ni<=0);

			int nLength=num.length();     // num���פj�p���mLength
			byte buffer6[]=new byte[nLength];
			buffer6=num.getBytes();
            DatagramPacket packet6= new DatagramPacket(buffer6,nLength,addr,portNo);    //�T���ʥ](��,�j�p,Server��},Server port)
            socket.send(packet6); //��num��packet6�ǰe

			 while(true)
			 {
			  if(count==0)//��count=0 �� �]�w��l�ɶ�
			  time_s=System.currentTimeMillis();

		      System.out.print("ClentIP:"+clientIP+">>�п�J�A�n�q���r��:");
		   	  String msg=uip.readLine();    //ŪUIP�����T��
			  count++;                      //�C�q1������+1
			  int mLength=msg.length();     //�Nmsg(�Ʀr)���פj�p���mLength
			  byte buffer3[]=new byte[mLength];
			  buffer3=msg.getBytes();
              DatagramPacket packet3= new DatagramPacket(buffer3,mLength,addr,portNo);    //�T���ʥ](��,�j�p,Server��},Server port)
              socket.send(packet3);    //�e�Xpacket�ʥ]�T��

		      DatagramPacket packet4= new DatagramPacket (buffer4,buffer4.length);  //�إ�Datagram packet��ƫʥ],����packet�ȩM���פj�p
			  socket.receive(packet4);   //�����ʥ]

			  String AB=new String(buffer4,0,packet4.getLength());  //�N�T���ର�r��
			  System.out.println("�A�Ҳq�����G�O"+AB);    //print xAxB
			  if(AB.equals(ni+"A0B"))              //���������
			  {
		         double time_e=System.currentTimeMillis();
			     double time_total=(time_e-time_s)/1000;
			     System.out.println("���߲q��F!!");
			     System.out.println("�@�q�F"+count+"��");//print����
			 	 System.out.println("��O" +time_total+"��");//print �ɶ�
			 	 count=0;		 //�����k0
		     	 System.out.print("�O�_�~��q?<y/n>");
			 	 str=scn.nextLine();
			 	 int sLength=str.length();     //�Nstr���פj�p���sLength
			 	 byte buffer5[]=new byte[sLength];
			 	 buffer5=str.getBytes();
	         	 DatagramPacket packet5= new DatagramPacket(buffer5,sLength,addr,portNo);    //�T���ʥ](��,�j�p,��},port)
	         	 socket.send(packet5);    //�e�Xpacket�ʥ]�T��
	             break;    //�q����X�j��
			 }
            }
             if(str.equals("N")||str.equals("n")) //��J(n/N)�ɵ����åB����socket
			 {
			 socket.close(); 
			 break; //���X�̥~����while�j��
			 }
		   }
  }
}
