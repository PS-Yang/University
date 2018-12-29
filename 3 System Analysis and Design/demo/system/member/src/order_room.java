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
class order_room extends JFrame implements ItemListener,ActionListener
{
	static order_room frm=new order_room();
	static ImageIcon left=new ImageIcon("bed2.jpg");
	static ImageIcon left1=new ImageIcon("bed4.jpg");
	static ImageIcon left2=new ImageIcon("bed8.jpg");
	static JLabel lab = new JLabel("請輸入房數 : ");
	static TextField txf=new TextField(18);
	static JLabel lab1 = new JLabel("請選擇訂票種類");
	static JLabel labp1= new JLabel("$123");
	static JLabel labp2= new JLabel("$123"); ;
	static JLabel labp3= new JLabel("$123");;
    static Checkbox ckb1=new Checkbox("雙人房");
    static Checkbox ckb2=new Checkbox("四人房");
    static Checkbox ckb3=new Checkbox("八人房");
    static JButton btn=new  JButton("確認訂票(confirm your book)");
    static JButton btn1=new JButton("Back");
    static JButton btn2=new JButton("",left);
    static JButton btn3=new JButton("",left1);
    static JButton btn4=new JButton("",left2);
    static String url="http://127.0.0.1/system/";
    static int ck=0;
    static String acount;
    static String pro_result; //pro 0 1
    static int c;
	
	public static void counti(int count)
	{
		c=count;
	}
    public static void order_room()
    {
    	if(c==0)
    	{
	    	c++;
    		btn.addActionListener(frm);
			btn1.addActionListener(frm);
			btn2.addActionListener(frm);
			btn3.addActionListener(frm);
			btn4.addActionListener(frm);
			ckb1.addItemListener(frm);
		    ckb2.addItemListener(frm);
		    ckb3.addItemListener(frm);
			order_rooma();
    	}
    	else
    		order_rooma();
    }
    public static void order_rooma()
    {
    	get_pro(acount);
    	
			
	    CheckboxGroup grp=new CheckboxGroup();
	    frm.setTitle("訂 房");
	    frm.setSize(500,500); 
	    
	    ImageIcon bg = new ImageIcon("good4.jpg");
		JLabel label = new JLabel(bg);
		label.setBounds(0,0,bg.getIconWidth(),bg.getIconHeight());
		frm.getLayeredPane().add(label,new Integer(Integer.MIN_VALUE));
		JPanel jp=(JPanel)frm.getContentPane();
		jp.setOpaque(false);
	    
	    frm.setLayout(null);
	    ckb1.setCheckboxGroup(grp);
	    ckb2.setCheckboxGroup(grp);
	    ckb3.setCheckboxGroup(grp);
	    
	    //txf.addKeyListener(new KeyLis());
	    lab1.setLocation(200,10);
	    lab1.setSize(200,20);
	    //
	    ckb1.setLocation(50,65);
	    ckb1.setSize(60,20);
	    btn2.setLocation(300,50);
	    btn2.setSize(100,50);
	    //
	    ckb2.setLocation(50,140); 
	    ckb2.setSize(60,20);
	    btn3.setLocation(300,125);
	    btn3.setSize(100,50);
	    //
	    ckb3.setLocation(50,215);
	    ckb3.setSize(60,20);
	    btn4.setLocation(300,200);
	    btn4.setSize(100,50);
	    //
	    labp1.setBounds(215,65,50,20);
	    labp2.setBounds(215,140,50,20);
	    labp3.setBounds(215,215,50,20);
	    txf.setLocation(260,310);
	    txf.setSize(50,20);
	    lab.setLocation(165,310);
	    lab.setSize(75,20);
	    btn.setLocation(50,350);
	    btn.setSize(150,50);
	    btn1.setLocation(250,350);
	    btn1.setSize(150,50);
	    if(pro_result.equals("0"))	
	    	labp1.setText("$2000");
	    else
	    	labp1.setText("$2500");
	    
	    if(pro_result.equals("0"))
	    	labp2.setText("$3000");
	    else
	    	labp2.setText("$3500");
	    
	    if(pro_result.equals("0"))
	    	labp3.setText("$4000");
	    else
	    	labp3.setText("$4500");
	    
	    
	    frm.add(lab1);
	    frm.add(labp1);
	    frm.add(labp2);
	    frm.add(labp3);
	    frm.add(ckb1);
	    frm.add(ckb2);
	    frm.add(ckb3);
	    frm.add(lab);
	    frm.add(txf);
	    frm.add(btn);
	    frm.add(btn1);
	    frm.add(btn2);
	    frm.add(btn3);
	    frm.add(btn4);
	    frm.setVisible(true);
    }
    public static void get(String id)
    {
    	acount=id;
    }
    public void actionPerformed(ActionEvent e)
	{
		JButton but=(JButton) e.getSource();
		ck=0;
		if(but==btn)
		{
			itemStateChanged(null);
			System.out.println(txf.getText().toString());
			System.out.println(acount);
			if(ck==1)
				 order_send(acount,txf.getText().toString(),"0","0");
			if(ck==2)
				 order_send(acount,"0",txf.getText().toString(),"0");
			if(ck==3)
				 order_send(acount,"0","0",txf.getText().toString());
			
			select.select();
			setVisible(false);
		}
		if(but==btn1)//back
		{
			select.select();
			setVisible(false);
		}
		if(but==btn2)
		{
			pic.pic6();
		}
		if(but==btn3)
		{
			pic.pic1();
		}
		if(but==btn4)
		{
			pic.pic2();
		}
		
	}
	@Override
	public void itemStateChanged(ItemEvent arg0) 
	{
		if(ckb1.getState()==true)
			ck=1;
		if(ckb2.getState()==true)
			ck=2;
		if(ckb3.getState()==true)
			ck=3;
	}
	
	/***********送出訂購**************************/
	public void order_send(String account,String doub,String four,String eight)
	{
	      try {
	      	HttpClient client = new DefaultHttpClient();
	      	HttpGet get = new HttpGet(url+"orders_modify.php?account="+account+"&doub="+doub+"&four="+four+"&eight="+eight);
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

}
