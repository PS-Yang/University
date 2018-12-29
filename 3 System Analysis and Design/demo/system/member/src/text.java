import javax.swing.*;

import java.awt.*;
import java.awt.event.*;

class text extends JFrame implements ItemListener,ActionListener
{
	static text frm=new text();
	static JPanel pRadio;
	static JPanel pProg;
	static JPanel pSys;
	static JPanel pCard;
	static JPanel J;
	static JLabel j1=new JLabel(" ",JLabel.CENTER);
	static JLabel j2=new JLabel(" ",JLabel.CENTER);
	static JLabel j3=new JLabel(" ",JLabel.CENTER);
	static JLabel s1=new JLabel("雙人房",JLabel.CENTER);
	static JLabel s2=new JLabel("四人房",JLabel.CENTER);
	static JLabel s3=new JLabel("八人房",JLabel.CENTER);
	static JLabel t1=new JLabel("遊樂場",JLabel.CENTER);
	static JLabel t2=new JLabel("美食",JLabel.CENTER);
	static JLabel t3=new JLabel("紀念品",JLabel.CENTER);
	static ImageIcon i1=new ImageIcon("bed2.jpg");
	static ImageIcon i2=new ImageIcon("bed4.jpg");
	static ImageIcon i3=new ImageIcon("bed8.jpg");
	static ImageIcon i4=new ImageIcon("tic1.jpg");
	static ImageIcon i5=new ImageIcon("tic2.jpg");
	static ImageIcon i6=new ImageIcon("tic3.jpg");
	static JLabel p1=new JLabel(i1);
	static JLabel p2=new JLabel(i2);
	static JLabel p3=new JLabel(i3);
	static JLabel p4=new JLabel(i4);
	static JLabel p5=new JLabel(i5);
	static JLabel p6=new JLabel(i6);
	
    static Container contentPane;
    static JRadioButton rProg = new JRadioButton("房間資訊",true); 
    static JRadioButton rSys = new JRadioButton("票券種類");
    static JButton JB=new JButton("返回");;
    static int c;
	
	public static void counti(int count)
	{
		c=count;
	}
    public static void text()
    {
    	if(c==0)
    	{
    		c++;
    		rProg.addItemListener(frm); 
    		rSys.addItemListener(frm);
    	    pRadio = new JPanel(new GridLayout(1, 1));
    		pRadio.add(rProg);
    	    pRadio.add(rSys);
    		JB.addActionListener(frm);
    		contentPane = frm.getContentPane();
    	    contentPane.setLayout(new GridLayout(3, 1));
    	    ButtonGroup bp = new ButtonGroup();
    	    bp.add(rProg);
    	    bp.add(rSys); 
    	    pProg = new JPanel(new GridLayout(1,1));
    	    J = new JPanel(new GridLayout(3, 1));
    	    pSys = new JPanel(new GridLayout(1, 5));
    	    pCard = new JPanel(new CardLayout());
    	    ((CardLayout) pCard.getLayout()).show(pCard, "Prog");
    	    pCard.add("Prog", pProg);
    	    pCard.add("Sys", pSys);
    	    contentPane.add(pRadio);
    	    contentPane.add(pCard);
    	    contentPane.add(J);
    		texta();
    	}
    	else
    		texta();
    }
    public static void texta()
    {
		//mainFrame = new JFrame("Layout Test");
	    pProg.add(s1);
	    pProg.add(p1);
	    pProg.add(s2);
	    pProg.add(p2);
	    pProg.add(s3);
	    pProg.add(p3);
	    
		J.add(j1);
		J.add(j2);
		J.add(j3);
		J.add(JB);

	    pSys.add(t1);
	    pSys.add(p4);
	    pSys.add(t2);
	    pSys.add(p5);
	    pSys.add(t3);
	    pSys.add(p6);

	    frm.pack();
	    frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frm.setVisible(true);
    }
    public void itemStateChanged(ItemEvent e)
    {
	    if(e.getStateChange() == e.SELECTED)
	    {
	    	if (e.getSource() == rProg)
	    		((CardLayout) pCard.getLayout()).show(pCard, "Prog");
	    	if (e.getSource() == rSys)
	    		((CardLayout) pCard.getLayout()).show(pCard, "Sys");
	    	validate();
     	}
     }
     public void actionPerformed(ActionEvent e)
     {
		JButton but=(JButton) e.getSource();
		if(but==JB)
		{
			select.select();
			setVisible(false);
		}
     }
}