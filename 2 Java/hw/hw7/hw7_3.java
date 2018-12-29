import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class hw7_3 extends JFrame implements ActionListener
{
    static hw7_3 frm=new hw7_3();
    static Container contentPane = frm.getContentPane();
    static WinLis wlis=new WinLis();
    static JButton but[];
    static JTextField txt=new JTextField("",18);

    public static void main(String[] args)
    {
     but=new JButton[10];
     frm.setTitle("�p���");
     contentPane.setLayout(null);
     frm.setSize(350,350);

     JPanel panel1 = new JPanel(new FlowLayout(FlowLayout.CENTER));//panel1
     panel1.add(txt);
     panel1.setBounds(50,30,200,50);

     JPanel panel2 = new JPanel(new GridLayout(3,3));  //panel2
     for(int i=1;i<=9;i++)
     {
     	panel2.add(but[i]=new JButton(Integer.toString(i)));
        but[i].addActionListener(frm);
     }
     panel2.setBounds(50,80,200,200);

     frm.addWindowListener(wlis);
     contentPane.add(panel1);
     contentPane.add(panel2);
     frm.setVisible(true);
    // frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e)
    {
      JButton bt=(JButton) e.getSource();
      txt.setHorizontalAlignment(JTextField.RIGHT);
      for(int i=1;i<=9;i++)
      {
      	if(bt==but[i])
      	{
      	 txt.setText(Integer.toString(i));
      	}
      }
    }
    static class WinLis extends WindowAdapter
    {
      public void windowClosing(WindowEvent e)
      {
       frm.dispose();
      }
     /* public void windowClosed(WindowEvent e){}      //��������
      public void windowDeactivated(WindowEvent e){} //�ܦ��D�@�Τ�����
      public void windowActivated(WindowEvent e){}   //�ܦ��@�Τ�����
      public void windowDeiconified(WindowEvent e){} //�����٭�
      public void windowIconified(WindowEvent e){}   //�����̤p��
      public void windowOpened(WindowEvent e){}      //�}�ҵ���*/
    }
}