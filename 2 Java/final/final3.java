import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;
public class final3
{
   public static void main(String[] arg)
   {
      try
    {
      Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
      String str="jdbc:odbc:DRIVER=Microsoft Access Driver (*.mdb);DBQ=c:\\db2.mdb";
      Connection con=DriverManager.getConnection(str,"user","pwd");
      System.out.println("資料庫連線測試成功！");

      Statement stmt=con.createStatement();
      ResultSet rs=stmt.executeQuery("select * from students ");
      while(rs.next())
      {
      	String stud_no=rs.getString(1);
        String stud_name=rs.getString(2);
        String stud_sex=rs.getString("stud_sex");
        String stud_addr=rs.getString("stud_addr");
      	String [][]data = new String[][] {{rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4) }};

        System.out.println(stud_no+","+stud_name+","+stud_sex+","+stud_addr);
      }



       JFrame frm = new JFrame("JTable1");
      Container contentPane = frm.getContentPane();

      String [] heading = new String[] {"學號","姓名","性別","地址"};

      contentPane.add(scrollPane,BorderLayout.CENTER);
       JTable table1=new JTable(data,heading);
      JScrollPane scrollPane = new JScrollPane(table1);
      frm.setSize(350,220);
      frm.setVisible(true);
      frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      con.close();
    }
    catch(ClassNotFoundException e)
    {
      System.out.println("找不到驅動程式類別");
      e.printStackTrace();
    }
    catch(SQLException e)
    {
      e.printStackTrace();
    }


   }
}