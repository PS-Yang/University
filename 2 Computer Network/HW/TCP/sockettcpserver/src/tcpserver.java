import java.net.*;
import java.io.*;
import java.util.Scanner;
 
// 1. ���{�������P TcpClient.java �{���f�t����A�����楻�{���A���� UdpClient�C
// 2. �����k : java TcpServer
 
public class tcpserver {
    public static int port = 20; // �s����
 
    public static void main(String args[]) throws Exception {
        ServerSocket ss = new ServerSocket(port);     // �إ� TCP ���A���C
        while (true) {                                // ���_�������B�z��J�T���C
            Socket sc = ss.accept();                // ������J�T���C���H�n��A�إ�socket,�N��accept�ʧ@
            OutputStream os = sc.getOutputStream();    // ���o��X��y�C
            Scanner scanner = new Scanner(System.in);  // �������o�ϥΪ̪���J�r��
            String st = scanner.next();
            os.write(st.getBytes("UTF-8"));// �e�T���� Client �ݡC
            System.out.printf("�A��J���O:" + st);          // �зǿ�X
            os.close();                                // ������X��y�C
            sc.close();                                // ���� TCP ���A���C
        }
    }
}