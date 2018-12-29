import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class final2 extends JFrame implements ActionListener
{
    static final2 frm=new final2();
    static Container contentPane = frm.getContentPane();

    static JTextField tx1=new JTextField(10);
    static JTextField tx2=new JTextField(10);

    static JTextArea txt=new JTextArea(25,10);

    static JButton but1;
    static JButton but2;

    static  JRadioButton r1 = new JRadioButton("男生");
    static  JRadioButton r2 = new JRadioButton("女生");
    static  ButtonGroup bgroup1 = new ButtonGroup();

    static String[] s = {"台北市","台中市","台南市","高雄市"};
    static JComboBox combo1 = new JComboBox(s);
    public static void main(String[] args)
    {
     but1=new JButton("新增存檔");
     but2=new JButton("顯示檔案內容");
     but1.addActionListener(frm);
     but2.addActionListener(frm);

     JFrame frm=new JFrame("個人資料登入");
     frm.setSize(400,400);

     Container contentPane = frm.getContentPane();
     contentPane.setLayout(null);
     JLabel lab = new JLabel("學生個人基本資料",JLabel.CENTER);
     lab.setBounds(30,10,200,20);
     contentPane.add(lab);

     JPanel p1 = new JPanel();
     JLabel lab1 = new JLabel("學號:",JLabel.LEFT);
     // tx1.setBounds(20,30,12,5);
     JLabel lab2 = new JLabel("姓名:",JLabel.LEFT);
    // tx2.setBounds(50,30,12,5);
   //  lab2.setBounds(40,30,12,2);
     p1.add(lab1);
     p1.add(tx1);
     p1.add(lab2);
     p1.add(tx2);
     p1.setBounds(0,50,400,25);
	 contentPane.add(p1);

	 JPanel p2 = new JPanel();
     //p2.setLayout(new GridLayout(1,3));
     JLabel lab3 = new JLabel("性別:",JLabel.LEFT);
     p2.add(lab3);

     p2.add(r1);
     p2.add(r2);

     bgroup1.add(r1);
     bgroup1.add(r2);
     contentPane.add(p2);
     p2.setBounds(20,100,150,50);

     JLabel lab4 = new JLabel("地址:",JLabel.LEFT);


     JPanel p3 = new JPanel();
     p3.add(lab4);
     p3.add(combo1);
     contentPane.add(p3);
     p3.setBounds(180,100,200,50);



     but1.setBounds(20,150,120,30);
     but2.setBounds(180,150,120,30);



     contentPane.add(but1);
     contentPane.add(but2);

     txt.setBounds(5,200,350,150);
     contentPane.add(txt);

     frm.setVisible(true);
     frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e)
    {
      JButton bt=(JButton) e.getSource();
      if(bt==but1)
      {
       String sh=tx1.getText();
       String name=tx2.getText();
       //String sex=(String)bgroup1.getSelectedItem();
       String loc=(String)combo1.getSelectedItem();

      }
      if(bt==but2)
      {

      }
    }
}