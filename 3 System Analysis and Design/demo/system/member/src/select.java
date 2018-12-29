import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class select extends JFrame implements ActionListener
{
	static select frm=new select();
	static JLabel lab = new JLabel("");
	static JLabel lab1 = new JLabel("歡迎光臨訂購系統，請選擇服務項目:");
	static JButton btn = new JButton("我要訂房");
	static JButton btn1 = new JButton("我要訂票");
	static JButton btn2 = new JButton("訂購項目介紹");
	static JButton btn3 = new JButton("訂單查詢");
	static JButton btn4 = new JButton("登出");
	static int c;
	
	public static void counti(int count)
	{
		c=count;
	}

	public static void select()
	{
		if(c==0)
		{
			c++;
			btn.addActionListener(frm);
			btn1.addActionListener(frm);
			btn2.addActionListener(frm);
			btn3.addActionListener(frm);
			btn4.addActionListener(frm);
			selecta();
		}
		else
			selecta();
	}
	public static void selecta()
	{

		frm.setLayout(null);
		frm.setSize(500,500);
		ImageIcon bg = new ImageIcon("good.jpg");
		JLabel label = new JLabel(bg);
		label.setBounds(0,0,bg.getIconWidth(),bg.getIconHeight());
		frm.getLayeredPane().add(label,new Integer(Integer.MIN_VALUE));
		JPanel jp=(JPanel)frm.getContentPane();
		jp.setOpaque(false);
		JPanel panel=new JPanel();
		panel.setOpaque(false);
		panel.setLayout(null);

		ImageIcon bgh = new ImageIcon("house.jpg");
		JLabel pic = new JLabel(bgh);
		pic.setBounds(70,110,170,120);
		frm.add(pic);
		ImageIcon bgt = new ImageIcon("ticket.jpg");
		JLabel pic1 = new JLabel(bgt);
		pic1.setBounds(250,110,170,120);
		frm.add(pic1);

		JButton button=new JButton("OK");
		button.setSize(100, 20);
		button.setLocation(100, 50);
		panel.add(button);
		frm.add(panel);

		frm.add(lab);
		lab.setBounds(100,60,400,50);

		frm.add(lab1);
		lab1.setBounds(150,20,200,20);
		lab1.setForeground(Color.blue);

		frm.add(btn);
     	btn.setBounds(70,320,150,50);
     	frm.add(btn1);
     	btn1.setBounds(270,320,150,50);
     	frm.add(btn2);
     	btn2.setBounds(70,250,350,50);//house
     	frm.add(btn3);
     	btn3.setBounds(70,390,150,50);
     	frm.add(btn4);
     	btn4.setBounds(270,390,150,50);

     	frm.setVisible(true);
     	frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent e)
	{
		JButton but=(JButton) e.getSource();
		if(but==btn)
		{
			order_room.order_room();
			setVisible(false);
		}
		if(but==btn2)
		{
			text.text();
			setVisible(false);
		}
		if(but==btn1)
		{
			order_ticket.order_ticket();
			setVisible(false);
		}
		if(but==btn4)
		{
			login.login();
			setVisible(false);
		}
		if(but==btn3)
		{
			itemlist.itemlist();
			setVisible(false);
		}
	}
}