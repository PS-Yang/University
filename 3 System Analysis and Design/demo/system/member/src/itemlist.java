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
class itemlist extends JFrame implements ActionListener
{
	static String url="http://127.0.0.1/system/";
	static String pro_result;
	static String orders_content="";
	static String doub_room;
	static String four_room;
	static String eight_room;
	static String playground_sum;
	static String food_sum;
	static String sou_sum;
	
	static itemlist frm=new itemlist();
	static JLabel label1=new JLabel("雙人房");
	static JLabel label2=new JLabel("22");
	static JLabel label3=new JLabel("");
	static JLabel label4=new JLabel("四人房");
	static JLabel label5=new JLabel("55");
	static JLabel label6=new JLabel("");
	static JLabel label7=new JLabel("八人房");
	static JLabel label8=new JLabel("88");
	static JLabel label9=new JLabel("");
	static JLabel label10=new JLabel("遊樂券");
	static JLabel label11=new JLabel("11");
	static JLabel label12=new JLabel("");
	static JLabel label13=new JLabel("美食券");
	static JLabel label14=new JLabel("14");
	static JLabel label15=new JLabel("");
	static JLabel label16=new JLabel("紀念券");
	static JLabel label17=new JLabel("17");
	static JLabel label18=new JLabel("");
	static JLabel label19=new JLabel("");
	static JButton but=new JButton("刪除");
	static JButton but1=new JButton("返回");
	static JButton but2=new JButton("付費");
	static String acount;
	static String person_sum;
	static int sum_sum;
	static int c;
	
	public static void counti(int count)
	{
		c=count;
	}
	public static void get(String id)
    {
    	acount=id;
    }
	public static void itemlist()
	{
		if(c==0)
		{
			c++;
			but.addActionListener(frm);
			but1.addActionListener(frm);
			but2.addActionListener(frm);
			itemlista();
		}
		else
			itemlista();
	}
	public static void itemlista()
	{
		get(acount);
		get_pro(acount);
		get_orders(acount);
	    get_sum(acount);
		label3.setText(doub_room);
		label6.setText(four_room);
		label9.setText(eight_room);
		label12.setText(playground_sum);
		label15.setText(food_sum);
		label18.setText(sou_sum);
		if(pro_result.equals("0"))
	  		label2.setText("$2000");
	    else
	    	label2.setText("$2500");
	    
	    if(pro_result.equals("0"))
	    	label5.setText("$3000");
	    else
	    	label5.setText("$3500");
	    
	    if(pro_result.equals("0"))
	    	label8.setText("$4000");
	    else
	    	label8.setText("$4500");
	    
	    if(pro_result.equals("0"))
	    	label11.setText("$200");
	    else
	    	label11.setText("$250");
	    
	    if(pro_result.equals("0"))
	    	label14.setText("$150");
	    else
	    	label14.setText("$200");
	    
	    if(pro_result.equals("0"))
	    	label17.setText("$180");
	    else
	    	label17.setText("$210");
	    int sum=0;
	    if(pro_result.equals("0"))
	    {
	    	sum=2000*Integer.parseInt(doub_room)+3000*Integer.parseInt(four_room)+4000*Integer.parseInt(eight_room)+200*Integer.parseInt(playground_sum)+150*Integer.parseInt(food_sum)+180*Integer.parseInt(sou_sum);
	    	
	    	sum_sum=Integer.parseInt(person_sum)-sum;
	    	
	    	label19.setText("剩餘"+person_sum+"元,共"+String.valueOf(sum)+"元");
	    	label19.setForeground(Color.red);
	    }
	    else
	    {
	    	sum=2500*Integer.parseInt(doub_room)+3500*Integer.parseInt(four_room)+4500*Integer.parseInt(eight_room)+250*Integer.parseInt(playground_sum)+200*Integer.parseInt(food_sum)+210*Integer.parseInt(sou_sum);
	    	
	    	sum_sum=Integer.parseInt(person_sum)-sum;
	    	
	    	label19.setText("剩餘"+person_sum+"元,共"+String.valueOf(sum)+"元");
	    	label19.setForeground(Color.red);
	    }
	    	
	    ImageIcon bg = new ImageIcon("good6.jpg");
		JLabel label = new JLabel(bg);
		label.setBounds(0,0,bg.getIconWidth(),bg.getIconHeight());
		frm.getLayeredPane().add(label,new Integer(Integer.MIN_VALUE));
		JPanel jp=(JPanel)frm.getContentPane();
		jp.setOpaque(false);
		
		frm.setLayout(null);
		frm.add(label1);
		label1.setBounds(65,50,100,20);
		frm.add(label2);
		label2.setBounds(175,50,100,20);
		frm.add(label3);
		label3.setBounds(285,50,100,20);
		frm.add(label4);
		label4.setBounds(65,80,100,20);
		frm.add(label5);
		label5.setBounds(175,80,100,20);
		frm.add(label6);
		label6.setBounds(285,80,100,20);
		frm.add(label7);
		label7.setBounds(65,110,100,20);
		frm.add(label8);
		label8.setBounds(175,110,100,20);
		frm.add(label9);
		label9.setBounds(285,110,100,20);
		frm.add(label10);
		label10.setBounds(65,140,100,20);
		frm.add(label11);
		label11.setBounds(175,140,100,20);
		frm.add(label12);
		label12.setBounds(285,140,100,20);
		frm.add(label13);
		label13.setBounds(65,170,100,20);
		frm.add(label14);
		label14.setBounds(175,170,100,20);
		frm.add(label15);
		label15.setBounds(285,170,100,20);
		frm.add(label16);
		label16.setBounds(65,200,100,20);
		frm.add(label17);
		label17.setBounds(175,200,100,20);
		frm.add(label18);
		label18.setBounds(285,200,100,20);
		frm.add(but);
		but.setBounds(60,300,100,30);
		frm.add(but1);
		but1.setBounds(210,300,100,30);
		label19.setBounds(70,255,200,20);
		frm.add(label19);
		but2.setBounds(220,250,80,30);
		if(sum<=Integer.parseInt(person_sum))
			frm.add(but2);
		else
			frm.remove(but2);
		
		frm.setSize(380,400);
		frm.setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e) 
	{
		// TODO Auto-generated method stub
		JButton button=(JButton) e.getSource();
		if(button==but)
		{
			order_de(acount);
			select.select();
		}
		if(button==but1)
		{
			select.select();
			setVisible(false);
		}
		if(button==but2)
		{
			sum_modify(acount,sum_sum);
			order_de(acount);
		}
		
	}
	/***********取得職業**************************/
	public static  void get_pro(String id)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"check_pro.php?id="+id);
	      	
	      	HttpResponse res = client.execute(get);
	      	HttpEntity he = res.getEntity();
	      	
	      	BufferedReader reader = new BufferedReader(
					new InputStreamReader(he.getContent()));
			String raw;
			
			while ((raw = reader.readLine()) != null)
			{
				pro_result=raw;
			}
			
			System.out.println(pro_result);
			reader.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	/***********取得定購表單**************************/
	public static  void get_orders(String id)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"orders_find.php?account="+id);
	      	HttpResponse res = client.execute(get);
	      	HttpEntity he = res.getEntity();
	      	
	      	BufferedReader reader = new BufferedReader(
					new InputStreamReader(he.getContent()));
			String raw;
			
			while ((raw = reader.readLine()) != null)
			{
				orders_content=raw;
			}
			int pos_four = orders_content.indexOf("四");
			int pos_eig = orders_content.indexOf("八");
			int pos_play = orders_content.indexOf("遊");
			int pos_fo = orders_content.indexOf("食");
			int pos_sou = orders_content.indexOf("紀");
			
			
			doub_room=orders_content.substring(0, pos_four);
			four_room=orders_content.substring(pos_four+1,pos_eig);
			eight_room=orders_content.substring(pos_eig+1,pos_play);
			playground_sum=orders_content.substring(pos_play+1,pos_fo);
			food_sum=orders_content.substring(pos_fo+1,pos_sou);
			sou_sum=orders_content.substring(pos_sou+1,orders_content.length());
			
			
			System.out.println(orders_content);
			reader.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	
	/***********取得定購金額**************************/
	public static  void get_sum(String id)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"check_sum.php?account="+id);
	      	HttpResponse res = client.execute(get);
	      	HttpEntity he = res.getEntity();
	      	
	      	BufferedReader reader = new BufferedReader(
					new InputStreamReader(he.getContent()));
			String raw;
			
			while ((raw = reader.readLine()) != null)
			{
				person_sum=raw;
			}
		
			
			
			System.out.println(person_sum);
			reader.close();

	      } catch (Exception e) {
	      	e.printStackTrace();
	      }
	}
	
	/***********刪除訂購**************************/
	public static void order_de(String account)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"orders_de.php?account="+account);
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
	/***********	金額修改**************************/
	public static void sum_modify(String account,int money)
	{
	      try
	      {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"sum_modify.php?account="+account+"&money="+money);
	      	HttpResponse res = client.execute(get);
	      	
	      	HttpEntity he = res.getEntity();
	      	InputStream in = he.getContent();
	      	int temp;
	      	while ( (temp = in.read()) != -1 ){
	      	}
	      	in.close();

	      } 
	      catch (Exception e) {
	      	e.printStackTrace();
	      }
	}

}
