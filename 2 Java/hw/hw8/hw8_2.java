import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class hw8_2 extends JFrame implements ActionListener
{
    static hw8_2 frm=new hw8_2();
    static Container cp = frm.getContentPane();
    static WinLis wlis=new WinLis();
    static JTextField txt1=new JTextField("",10);
    static JTextField txt2=new JTextField("",10);
    static JLabel lab=new JLabel("");
    public static void main(String[] args)
    {
     frm.setTitle("BMI指數計算");
     cp.setLayout(null);
     frm.setSize(350,350);

     JLabel lab1 = new JLabel("BMI指數計算",JLabel.CENTER);
     lab1.setBounds(80,20,100,10);
     cp.add(lab1);

     JButton but=new JButton("看結果");
     but.setBounds(115,160,100,30);
     cp.add(but);
     but.addActionListener(frm);

     JLabel lab2 = new JLabel("身高(cm): ",JLabel.LEFT);
     JLabel lab3 = new JLabel("體重(kg) : ",JLabel.LEFT);
     JLabel lab4 = new JLabel("診斷結果:",JLabel.LEFT);

     JPanel p1 = new JPanel(new FlowLayout(FlowLayout.LEFT));//panel1
     p1.add(lab2);
     p1.add(txt1);
     p1.setBounds(50,40,200,30);
     cp.add(p1);

     JPanel p2 = new JPanel(new FlowLayout(FlowLayout.LEFT));//panel2
     p2.add(lab3);
     p2.add(txt2);
     p2.setBounds(50,80,200,30);
     cp.add(p2);

     JPanel p3 = new JPanel(new FlowLayout(FlowLayout.LEFT));//panel3

     p3.add(lab4);
     p3.add(lab);
     p3.setBounds(50,120,400,30);
     cp.add(p3);

     frm.addWindowListener(wlis);
     frm.setVisible(true);
    // frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

   public void actionPerformed(ActionEvent e)
    {
      int high=Integer.parseInt(txt1.getText());
      int wei=Integer.parseInt(txt2.getText());
      float bmi=(float)wei*10000/(high*high);

      if(bmi>=35)
      {
       lab.setText("BMI="+bmi+"(重度肥胖)");
       lab.setForeground(Color.red);
      }
      else if(bmi>=30)
      {
       lab.setText("BMI="+bmi+"(中度肥胖)");
       lab.setForeground(Color.red);
      }
      else if(bmi>=27)
      {
       lab.setText("BMI="+bmi+"(輕度肥胖)");
       lab.setForeground(Color.red);
      }
      else if(bmi>=24)
      {
       lab.setText("BMI="+bmi+"(過重)");
       lab.setForeground(Color.red);
      }
      else if(bmi>=18.5)
      {
       lab.setText("BMI="+bmi+"(正常範圍)");
       lab.setForeground(Color.blue);
      }
      else
      {
       lab.setText("BMI="+bmi+"(體重過輕)");
       lab.setForeground(Color.red);
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