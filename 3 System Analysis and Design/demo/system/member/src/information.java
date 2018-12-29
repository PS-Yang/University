import java.awt.*;
import javax.swing.*;

import java.awt.event.*;
import java.io.InputStream;

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

class information extends JFrame implements ActionListener
{
	static information frm = new information();
	static TextField id=new TextField("",15);
	static TextField pass=new TextField("",15);
	static TextField pass2=new TextField("",15);
	static TextField name=new TextField("",15);
	static TextField mail=new TextField("",15);
	static String[] s = {"學生","工業","漁業","農業","商業"};
	static JComboBox combo1 = new JComboBox(s);
	static String url="http://127.0.0.1/system/";
	static JButton but=new JButton("註冊");
	static JButton but1=new JButton("返回");
	static Label label=new Label("注意事項");
	static String result="";
	static int c;
	
	public static void counti(int count)
	{
		c=count;
	}
	public static void information()
	{
		if(c==0)
		{
			c++;
			but.addActionListener(frm);
			but1.addActionListener(frm);
			informationa();
		}
		else
			informationa();
	}
	public static void informationa()
	{
		frm.setLayout(null);

		Label lab1=new Label("會員註冊申請");
		lab1.setAlignment(Label.CENTER);
		
		frm.add(lab1);
		lab1.setBounds(140,20,120,20);

		Label lab2=new Label("帳　　號:");
		frm.add(lab2);
		lab2.setBounds(40,50,60,25);
		frm.add(id);
		id.setBounds(110,50,200,25);

	    Label lab3=new Label("密　　碼:");
	    pass.setEchoChar('*');
	    frm.add(lab3);
	    lab3.setBounds(40,100,60,25);
	    frm.add(pass);
	    pass.setBounds(110,100,200,25);
	    
		Label lab4=new Label("密碼確認:");
		pass2.setEchoChar('*');
    	frm.add(lab4);
    	lab4.setBounds(40,150,60,25);
    	frm.add(pass2);
    	pass2.setBounds(110,150,200,25);
    	

    	Label lab5=new Label("名　　字:");
    	frm.add(lab5);
    	lab5.setBounds(40,200,60,25);
    	frm.add(name);
    	name.setBounds(110,200,200,25);

    	Label lab6=new Label("信　　箱:");
    	frm.add(lab6);
    	lab6.setBounds(40,250,60,25);
    	frm.add(mail);
    	mail.setBounds(110,250,200,25);
 
    	combo1.addItem("學生");
    	Label lab7=new Label("職　　業:");
    	frm.add(lab7);
    	lab7.setBounds(40,300,60,25);
    	frm.add(combo1);
    	combo1.setBounds(110,300,200,25);
    	
     	frm.add(but);
     	but.setBounds(100,400,80,35);
     	
     	frm.add(but1);
     	but1.setBounds(200,400,80,35);
     	 
        frm.add(label);
     	label.setBounds(155,350,300,25);
     	
     	
		frm.setSize(400,500);
		frm.setBackground(Color.gray);

		frm.setVisible(true);
		frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent e)
	{
		JButton button=(JButton) e.getSource();
		if(button==but)
		{
			 check(id.getText().toString());
			 if(id.getText().length()==0 ||pass.getText().length()==0||pass2.getText().length()==0||name.getText().length()==0||mail.getText().length()==0)
			 {
				  label.setText("請確實填寫表單");
				  label.setForeground(Color.red);
			 }
			 else if(id.getText().length()<3 || id.getText().length()>15)
			 {
				 label.setText("帳號長度要介於3~15之間");
				 label.setForeground(Color.red); 
			 }
			 else if(pass.getText().length()<5 || pass.getText().length()>20)
			 {
				 label.setText("密碼長度要介於5~20之間");
				 label.setForeground(Color.red); 
			 }
			 else if(!pass.getText().toString().equals(pass2.getText().toString()))
			 {
				 label.setText("密碼輸入不一致");
				 label.setForeground(Color.red); 
			 }
			 else if(name.getText().length()<3 || name.getText().length()>10)
			 {
				 label.setText("名字長度介於3~10之間");
				 label.setForeground(Color.red); 
			 }
			 else if(mail.getText().length()<6 || mail.getText().length()>30)
			 {
				 label.setText("信箱長度介於6~30之間");
				 label.setForeground(Color.red); 
			 }
			 else if(result.equals("true"))
			 {
				 label.setText("帳號已被使用!!");
				 label.setForeground(Color.red); 
			 }
			 else
			 {	 
			      if(combo1.getSelectedIndex()==0)
			    	  connectsend(id.getText().toString(),pass.getText().toString(),name.getText().toString(),mail.getText().toString(),"0");
			      else if(combo1.getSelectedIndex()==1)
			    	  connectsend(id.getText().toString(),pass.getText().toString(),name.getText().toString(),mail.getText().toString(),"1");
			      else if(combo1.getSelectedIndex()==2)
			    	  connectsend(id.getText().toString(),pass.getText().toString(),name.getText().toString(),mail.getText().toString(),"1");  
			      else if(combo1.getSelectedIndex()==3)
			    	  connectsend(id.getText().toString(),pass.getText().toString(),name.getText().toString(),mail.getText().toString(),"1");  
			      else if(combo1.getSelectedIndex()==4)
			    	  connectsend(id.getText().toString(),pass.getText().toString(),name.getText().toString(),mail.getText().toString(),"1");  
			      order_insert(id.getText().toString());
			      label.setText("註冊成功");
			      label.setForeground(Color.blue); 
			      login.login();
					 setVisible(false);
			 }
			 
		}
		if(button==but1)
		{
			login.login();
			setVisible(false);
		}
		 
		 /*
		 System.out.println(combo1.getSelectedIndex());
		 
		 System.out.println(id.getText());
	      System.out.println(pass.getText());
	      System.out.println(pass.getText());
	      System.out.println(name.getText());
	      System.out.println(mail.getText());
		 */
		  

	}
	/***********傳送表單資料**************************/
	public void connectsend(String id,String pass,String name,String mail,String pro)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"register.php?id="+id+"&password="+pass+"&name="+name+"&mail="+mail+"&pro="+pro);
	      	HttpResponse res = client.execute(get);
	      	
	      	HttpEntity he = res.getEntity();
	      	InputStream in = he.getContent();
	      	int temp;
	      	while ( (temp = in.read()) != -1 ){
	      	}
	      	in.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	/***********檢查帳號**************************/
	public  void check(String id)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"check_account.php?id="+id);
	      	
	      	HttpResponse res = client.execute(get);
	      	HttpEntity he = res.getEntity();
	      	
	      	BufferedReader reader = new BufferedReader(
					new InputStreamReader(he.getContent()));
	      	
			String raw;
			
			
			while ((raw = reader.readLine()) != null)
			{
			  result=raw;
			}
			
			System.out.println(result);
			reader.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	/***********新增客戶定貨資料**************************/
	public void order_insert(String account)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"orders.php?account="+account);
	      	HttpResponse res = client.execute(get);
	      	
	      	HttpEntity he = res.getEntity();
	      	InputStream in = he.getContent();
	      	int temp;
	      	while ( (temp = in.read()) != -1 ){
	      	}
	      	in.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	
}