import java.net.*;
import java.io.*;
 
// 1. ���{�������P TcpServer.java �{���f�t����A������ TcpServer �A���楻�{���C
// 2. ���{���������@�ӰѼơA���w���A���� IP�C
// �Ϊk�d�ҡG java TcpClient 127.0.0.1
 
public class tcpclient {
    public static int port = 20; // �]�w�ǰe�� 20�C
 
    public static void main(String args[]) throws Exception {
        Socket client = new Socket("127.0.0.1", port);     // �ھ� args[0] �� TCP Socket.
        InputStream in = client.getInputStream();      // ���o��J�T������y
        StringBuffer buf = new StringBuffer();        // �إ�Ū���r��C
        try {
            while (true) {            // ���_Ū���C
                int x = in.read();    // Ū���@�� byte�C(read �Ǧ^ -1 �N���y����)
                if (x==-1) break;    // x = -1 �N���y�����AŪ�������A�� break ���}�C
                byte b = (byte) x;    // �N x �ର byte�A��J�ܼ� b.
                buf.append((char) b);// ���]�ǰeASCII�r�����O ASCII�C
            }
        } catch (Exception e) {
            in.close();                // ������J��y�C
        }
        System.out.println(buf);                    // �L�X�����쪺�T���C
        client.close();                                // ���� TcpSocket.
    }
}