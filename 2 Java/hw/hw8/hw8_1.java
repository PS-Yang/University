import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class hw8_1
{

    public static void main(String[] args)
    {

     JFrame frm=new JFrame("�ӤH��Ƶn�J");
     frm.setSize(350,450);
     //�ǥͰ򥻸��
     Container contentPane = frm.getContentPane();
     contentPane.setLayout(null);
     JLabel lab = new JLabel("�ǥͭӤH�򥻸��",JLabel.CENTER);
     lab.setBounds(30,10,200,20);
     contentPane.add(lab);
     //�m�W
     JPanel p1 = new JPanel();
     JLabel lab1 = new JLabel("�m�W:");
     JTextField txt1 = new JTextField("���p��",10);
     p1.add(lab1);
     p1.add(txt1);
     p1.setBounds(0,40,200,50);
	 contentPane.add(p1);
     //�ʧO
	 JPanel p2 = new JPanel();
     p2.setLayout(new GridLayout(1,2));
     JLabel lab2 = new JLabel("�ʧO:");
     JRadioButton r1 = new JRadioButton("�k��");
     JRadioButton r2 = new JRadioButton("�k��");
     p2.add(lab2);
     p2.add(r1);
     p2.add(r2);
     ButtonGroup bgroup1 = new ButtonGroup();
     bgroup1.add(r1);
     bgroup1.add(r2);
     contentPane.add(p2);
     p2.setBounds(0,80,200,50);
     //�t��
     String[] s = {"��T�u�{�t","���~�޲z�t","��T�޲z�t","�^�y�t","���t","���z�t"};
     JComboBox combo1 = new JComboBox(s);
     JLabel lab3 = new JLabel("�t��:");
     JPanel p3 = new JPanel();
     p3.add(lab3);
     p3.add(combo1);
     contentPane.add(p3);
     p3.setBounds(-35,130,200,50);
     //����
     JPanel p4 = new JPanel();
     p4.setLayout(new GridLayout(1,4));
     JLabel lab4 = new JLabel("����:");
     JCheckBox c1 = new JCheckBox("���x�y");
     JCheckBox c2 = new JCheckBox("��a");
     JCheckBox c3 = new JCheckBox("�C�]");
     p4.add(lab4);
     p4.add(c1);
     p4.add(c2);
     p4.add(c3);
     contentPane.add(p4);
     p4.setBounds(0,180,280,50);
     //�ۧڤ���
     JPanel p5 = new JPanel();
     p5.setLayout(new GridLayout(1,1));
     JTextArea area1 = new JTextArea(10,20);
     p5.add(area1);
     JScrollPane sp5 = new JScrollPane(p5);
     contentPane.add(sp5,BorderLayout.CENTER);
     sp5.setBounds(0,230,280,50);
     sp5.setBorder(BorderFactory.createTitledBorder("�ۧڤ���"));
     //�s��
     JPanel p6 = new JPanel();
     p6.setLayout(new GridLayout(1,1));
     JButton but=new JButton("�s��");
     p6.add(but);
     p6.setBounds(100,280,80,30);
     contentPane.add(p6);


     frm.setVisible(true);
     frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}