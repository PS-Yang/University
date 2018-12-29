import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class hw7_1
{
    static Frame frm=new Frame("計算機");
    static Label lab=new Label();
    public static void main(String[] args)
    {
     frm.setLayout(null);//取消版面配置
     frm.setSize(400,400);
     frm.setLocation(200,200);
     frm.setBackground(Color.white);

     lab.setText("0.");
     lab.setBackground(Color.pink);
     lab.setLocation(80,50);
     lab.setSize(240,20);

     for(int i=1;i<=9;i++)
     {
     	JButton bt=new JButton(Integer.toString(i));
     	bt.setBounds(80*(1+(i+2)%3),80*((i+2)/3),80,80);
     	frm.add(bt);
     }
     frm.add(lab);
     frm.setVisible(true);
     frm.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent e){System.exit(0);}});
    }
}