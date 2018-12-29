import java.awt.*;
import javax.swing.*;

import java.awt.event.*;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
@SuppressWarnings("serial")
class pic extends JFrame implements ActionListener
{
	static pic frm=new pic();
	static pic frm2=new pic();
	static pic frm3=new pic();
	static pic frm4=new pic();
	static pic frm5=new pic();
	static pic frm6=new pic();
	static ImageIcon left=new ImageIcon("bed2_1.jpg");
	static ImageIcon left1=new ImageIcon("bed4_1.jpg");
	static ImageIcon left2=new ImageIcon("bed8_1.jpg");
	static ImageIcon left3=new ImageIcon("tic1_1.jpg");
	static ImageIcon left4=new ImageIcon("tic2_1.jpg");
	static ImageIcon left5=new ImageIcon("tic3_1.jpg");
	static JButton btn1=new JButton("",left);
	static JButton btn2=new JButton("",left1);
	static JButton btn3=new JButton("",left2);
	static JButton btn4=new JButton("",left3);
	static JButton btn5=new JButton("",left4);
	static JButton btn6=new JButton("",left5);
	public static void pic6()
	{
		btn1.addActionListener(frm);
		frm.setSize(300,300);  
	    frm.setLayout(null);
	    btn1.setBounds(0,0,300,300);
	    frm.add(btn1);
	    frm.setVisible(true);
	}
	public static void pic1()
	{
		btn2.addActionListener(frm);
		frm2.setSize(300,300);  
	    frm2.setLayout(null);
	    btn2.setBounds(0,0,300,300);
	    frm2.add(btn2);
	    frm2.setVisible(true);
	}
	public static void pic2()
	{
		btn3.addActionListener(frm);
		frm3.setSize(300,300);  
	    frm3.setLayout(null);
	    btn3.setBounds(0,0,300,300);
	    frm3.add(btn3);
	    frm3.setVisible(true);
	}
	public static void pic3()
	{
		btn4.addActionListener(frm);
		frm4.setSize(300,300);  
	    frm4.setLayout(null);
	    btn4.setBounds(0,0,300,300);
	    frm4.add(btn4);
	    frm4.setVisible(true);
	}
	public static void pic4()
	{
		btn5.addActionListener(frm);
		frm5.setSize(300,300);  
	    frm5.setLayout(null);
	    btn5.setBounds(0,0,300,300);
	    frm5.add(btn5);
	    frm5.setVisible(true);
	}
	public static void pic5()
	{
		btn6.addActionListener(frm);
		frm6.setSize(300,300);  
	    frm6.setLayout(null);
	    btn6.setBounds(0,0,300,300);
	    frm6.add(btn6);
	    frm6.setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e) 
	{
		// TODO Auto-generated method stub
		JButton but=(JButton) e.getSource();
		if(but==btn1 || but==btn2 || but==btn3)
		{
			order_room.order_room();
			setVisible(false);
		}
		if(but==btn4 || but==btn5 || but==btn6)
		{
			order_ticket.order_ticket();
			setVisible(false);
		}
		
	}

}
