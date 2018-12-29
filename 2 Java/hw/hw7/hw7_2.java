import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class hw7_2
{

    public static void main(String[] args)
    {

     JFrame frm=new JFrame("­pºâ¾÷");
     Container contentPane = frm.getContentPane();
     contentPane.setLayout(null);
     frm.setSize(350,350);
     JPanel panel1 = new JPanel(new FlowLayout(FlowLayout.CENTER));
     panel1.add(new JTextField("0.",18));
     panel1.setBounds(50,30,200,50);
     JPanel panel2 = new JPanel(new GridLayout(3,3));
     for(int i=1;i<=9;i++)
     {
     	JButton but=new JButton(Integer.toString(i));
     	panel2.add(but);
     }
     panel2.setBounds(50,80,200,200);
     contentPane.add(panel1);
     contentPane.add(panel2);
     frm.setVisible(true);
     frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}