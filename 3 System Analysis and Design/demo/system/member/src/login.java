import java.awt.*;
import javax.swing.*;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import java.awt.event.*;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

class login extends JFrame implements ActionListener
{
	static login frm=new login();
	static JLabel lab = new JLabel("");
	static JLabel lab1 = new JLabel("歡迎光臨本系統");
	static JLabel lab2 = new JLabel("帳號 : ");
	static JLabel lab3 = new JLabel("密碼 : ");
	static JLabel lab4 = new JLabel("            ");
	static JButton btn = new JButton("登入");
	static JButton btn1 = new JButton("離開");
	static JButton btn2 = new JButton("註冊");
	static TextField txt1 = new TextField("",15);
	static TextField txt2 = new TextField("",15);
	static String url="http://127.0.0.1/system/";
	static String check_result="";
	static int c;
	
	public static void counti(int count)
	{
		c=count;
	}
	public static void login()
	{
		if(c==0)
		{
			c++;
			btn.addActionListener(frm);
			btn1.addActionListener(frm);
			btn2.addActionListener(frm);
			logina();
		}
		else
			logina();
	}
	public static void logina()
	{
		
		frm.setTitle("登入");
		
		txt1.setText("");
		txt2.setText("");
		frm.setSize(500,500);//350 300
		frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		ImageIcon bg = new ImageIcon("good2.jpg");
		JLabel label = new JLabel(bg);
		label.setBounds(0,0,bg.getIconWidth(),bg.getIconHeight());
		frm.getLayeredPane().add(label,new Integer(Integer.MIN_VALUE));
		JPanel jp=(JPanel)frm.getContentPane();
		jp.setOpaque(false);

		frm.setLayout(null);
		frm.add(lab1);
		lab1.setBounds(195,40,120,20);
		frm.add(lab);
		lab.setBounds(175,40,120,20);

		frm.add(lab2);
		frm.add(txt1);
		lab2.setBounds(155,100,70,20);
		txt1.setBounds(235,100,100,20);

		frm.add(lab3);
		frm.add(txt2);
		lab3.setBounds(155,155,70,20);
		txt2.setEchoChar('*');
		txt2.setBounds(235,155,100,20);

		frm.add(lab4);
		lab4.setBounds(125,180,70,20);
		frm.add(lab);
		lab.setBounds(195,210,200,20);

		frm.add(btn);
     	btn.setBounds(200,255,80,30);
     	frm.add(btn1);
     	btn1.setBounds(300,255,80,30);
     	
     	frm.add(btn2);
     	btn2.setBounds(100,255,80,30);
     	frm.setVisible(true);
	}
	public static void transid(String id)
	{
		order_room.get(id);
		order_ticket.get(id);
		itemlist.get(id);
	}

	public void actionPerformed(ActionEvent e)
	{
		JButton but=(JButton) e.getSource();
		if(but==btn1)
		{
			System.exit(0);
		}
		if((txt1.getText()).length() != 0 && (txt2.getText()).length() != 0)
		{
			transid(txt1.getText().toString());
			if(but==btn)
			{
				check(txt1.getText().toString(),txt2.getText().toString());
				if(check_result.equals("true"))
				{
					select.select();
					setVisible(false);
				}
				else
				{
					lab.setText("錯囉，請重新輸入!");
					lab.setForeground(Color.red);
				}
			}
		}
		else
		{
			lab.setText("請輸入帳號或密碼!");
			lab.setForeground(Color.red);
		}
		
		if(but==btn2)//註冊
		{
			information.information();
			setVisible(false);//關掉框框
		}
	}
	/***********檢查帳號密碼**************************/
	public  void check(String id,String pass)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"check.php?id="+id+"&password="+pass);
	      	
	      	HttpResponse res = client.execute(get);
	      	HttpEntity he = res.getEntity();
	      	
	      	BufferedReader reader = new BufferedReader(
					new InputStreamReader(he.getContent()));
			String raw;
			
			while ((raw = reader.readLine()) != null)
			{
				check_result=raw;
			}
			
			System.out.println(check_result);
			reader.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	
}