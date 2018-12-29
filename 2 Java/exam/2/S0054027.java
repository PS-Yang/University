import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class S0054027 extends JFrame implements ActionListener,ItemListener
{
    static S0054027 frm=new S0054027();
    static Container cp = frm.getContentPane();
    static WinLis wlis=new WinLis();

    static JTextField txt1=new JTextField("",5);
    static JTextField txt2=new JTextField("",5);
    static JLabel lab=new JLabel("");

    static Choice chc=new Choice();

    public static void main(String[] args)
    {
     frm.setTitle("四則運算");
     cp.setLayout(null);
     frm.setSize(350,300);
     JLabel lab1 = new JLabel("四 則 運 算",JLabel.CENTER);
     lab1.setBounds(80,20,100,20);
     cp.add(lab1);
     JButton but=new JButton("看結果");
     chc.add("+");
     chc.add("-");
     chc.add("*");
     chc.add("/");
     JPanel p1 = new JPanel(new FlowLayout(FlowLayout.LEFT)); //panel1
     p1.add(txt1);
     p1.add(chc);
     p1.add(txt2);
     p1.add(but);
     p1.setBounds(0,40,500,50);

     but.addActionListener(frm);
     chc.addItemListener(frm);
     cp.add(p1);

     lab.setBounds(50,80,200,50);
     lab.setForeground(Color.blue);
     lab.setFont(new Font ("Serief",Font.ITALIC+Font.BOLD,25));
     cp.add(lab);
     frm.addWindowListener(wlis);
     frm.setVisible(true);
    // frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

   public void actionPerformed(ActionEvent e)
    {
      int a=Integer.parseInt(txt1.getText());
      int b=Integer.parseInt(txt2.getText());
      String op=chc.getSelectedItem();
      if(op=="+")
         lab.setText(a+" + "+b+" = "+(a+b));
      if(op=="-")
         lab.setText(a+" - "+b+" = "+(a-b));
      if(op=="*")
         lab.setText(a+" * "+b+" = "+(a*b));
      if(op=="/")
         lab.setText(a+" / "+b+" = "+(a/b));
    }
    public void itemStateChanged(ItemEvent e){ }

    static class WinLis extends WindowAdapter
    {
      public void windowClosing(WindowEvent e)
      {
       frm.dispose();
      }
    }
}