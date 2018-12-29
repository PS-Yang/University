import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class final1 extends JFrame
{
    static S0054027 frm=new S0054027();
    static Container contentPane = frm.getContentPane();
    static WinLis wlis=new WinLis();
    static JTextArea txt=new JTextArea(25,10);
    static JLabel lab=new JLabel("");
    static  int count=0;
    public static void main(String[] args)
    {

     frm.setTitle("按鍵事件處理");
     contentPane.setLayout(null);
     frm.setSize(250,250);

     JPanel panel1 = new JPanel(new GridLayout(1,1));//panel1
     panel1.setBorder(BorderFactory.createTitledBorder("訊息"));
     panel1.add(txt);
     panel1.setBounds(5,5,170,100);

     txt.addKeyListener(new KeyLis());


     JPanel panel2 = new JPanel();  //panel2

     JLabel lab1 = new JLabel("數字總和:",JLabel.LEFT);
     panel2.setBounds(1,130,100,100);
     panel2.add(lab1);
     panel2.add(lab);

     frm.addWindowListener(wlis);
     contentPane.add(panel1);
     contentPane.add(panel2);
     frm.setVisible(true);
    }
   static class KeyLis extends KeyAdapter
   {
    public void keyPressed(KeyEvent e)
    {
     if(e.getKeyChar()=='1')
     count=count+1;
     else if(e.getKeyChar()=='2')
     count=count+2;
      else if(e.getKeyChar()=='3')
     count=count+3;
      else if(e.getKeyChar()=='4')
     count=count+4;
      else if(e.getKeyChar()=='5')
     count=count+5;
      else if(e.getKeyChar()=='6')
     count=count+6;
      else if(e.getKeyChar()=='7')
     count=count+7;
      else if(e.getKeyChar()=='8')
     count=count+8;
      else if(e.getKeyChar()=='9')
     count=count+9;

     lab.setText("      "+count);
     lab.setForeground(Color.blue);
    }
   }
    static class WinLis extends WindowAdapter
    {
      public void windowClosing(WindowEvent e)
      {
       frm.dispose();
      }
    }
}