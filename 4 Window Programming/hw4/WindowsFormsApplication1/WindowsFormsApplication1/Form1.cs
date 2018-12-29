using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


using System;
using System.IO;


namespace WindowsFormsApplication1
{

    public partial class Form1 : Form
    {
         
        String filePath = null;
        private Font myFont;

        public Form1()
        {
            InitializeComponent();
            myFont = Font;
            openToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.O;
            newToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.N;
            saveToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.S;
            printToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.P;
            searchToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.F;
        }
        public static String fileToText(String filePath)
        {
            StreamReader file = new StreamReader(filePath, System.Text.UTF8Encoding.UTF8/*Encoding.Unicode*/);
            String text = file.ReadToEnd();
            file.Close();
            return text;
        }
        public static void textToFile(String filePath, String text)
        {
            StreamWriter file = new StreamWriter(filePath );
            file.Write(text);
            file.Close();
        }

       

        private void openToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                String text = fileToText(openFileDialog.FileName);
                richTextBox.Text = text;
                filePath = openFileDialog.FileName;

            }
        }

        private void newToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            richTextBox.Text = "";
            filePath = null;
        }

        private void saveToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            if (filePath == null)
            {
                dialogSaveFile();
            }
            else
            {
                textToFile(filePath, richTextBox.Text);
            }
        }
        private void saveAsToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            dialogSaveFile();
        }
        public void dialogSaveFile()
        {
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                textToFile(saveFileDialog.FileName, richTextBox.Text);
                filePath = saveFileDialog.FileName;
            }
        }

        private void fontToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            FontDialog fontDialog = new FontDialog();

            fontDialog.Font = richTextBox.Font;
           // fontDialog.Color = richTextBox.ForeColor;

            if (fontDialog.ShowDialog() != DialogResult.Cancel)
            {
                //richTextBox.Font = fontDialog.Font;
                //richTextBox.ForeColor = fontDialog.Color;
                //  richTextBox.SelectionColor = fontDialog.Color;
                richTextBox.SelectionFont = fontDialog.Font;
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();

            colorDialog.Color = richTextBox.ForeColor;
            if (colorDialog.ShowDialog() != DialogResult.Cancel)
            {
                //richTextBox.Font = fontDialog.Font;
                //richTextBox.ForeColor = fontDialog.Color;
               
                richTextBox.SelectionColor = colorDialog.Color;
            }
        }

        private void backgroundColorToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();
          
            colorDialog.Color = richTextBox.ForeColor;
            if (colorDialog.ShowDialog() != DialogResult.Cancel)
            {
                //richTextBox.Font = fontDialog.Font;
                //richTextBox.ForeColor = fontDialog.Color;

                richTextBox.SelectionBackColor = colorDialog.Color;
            }
        }

        private void richTextBox_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                /* ContextMenuStrip contextMenuStrip= new ContextMenuStrip();
                 contextMenuStrip.Items.Add("Cut");
                 contextMenuStrip.Items.Add("copy");
                 contextMenuStrip.Items.Add("Paste");
                 contextMenuStrip.Items.Add("Undo");
                 contextMenuStrip.Items.Add("Redo");*/
               // Point startPoint = richTextBox.PointToScreen(new Point(e.X, e.Y));
                contextMenuStrip1.Show(richTextBox.PointToScreen(new Point(e.X, e.Y)) );
            }
        }

        private void toolStripMenuItem1_Click(object sender, System.EventArgs e)
        {
            richTextBox.Cut();
        }

        private void paseToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            richTextBox.Copy();
        }

        private void pasteToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            richTextBox.Paste();
        }

        private void undoToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            richTextBox.Undo();
        }

        private void redoToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            richTextBox.Redo();
        }
        private void selectAllToolStripMenuItem1_Click(object sender, System.EventArgs e)
        {
            richTextBox.SelectAll();
        }
        private void exitToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            Application.Exit();
        }

       

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
           
           /* if (e.Control && e.KeyCode == Keys.S)       // Ctrl-S Save
            {
                saveToolStripMenuItem_Click(sender, e); 
                e.SuppressKeyPress = true; // Stops bing! Also sets handled which stop event bubbling
            }
            if (e.Control && e.KeyCode == Keys.N)       
            {
                newToolStripMenuItem_Click(sender, e); 
                e.SuppressKeyPress = true; // Stops bing! Also sets handled which stop event bubbling
            }
            if (e.Control && e.KeyCode == Keys.O)       
            {
                openToolStripMenuItem_Click(sender, e); 
                e.SuppressKeyPress = true; // Stops bing! Also sets handled which stop event bubbling
            }*/

        }
        // MessageBox.Show("Pressed ");
        private void printToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
            if (printDialog1.ShowDialog() == DialogResult.OK)
            {

            }
        }

        private void searchToolStripMenuItem_Click(object sender, System.EventArgs e)
        {
           groupBox1.Visible = true;
            
        }

        private void button3_Click(object sender, System.EventArgs e)
        {
            groupBox1.Visible = false;
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            int p;
            if(richTextBox.SelectionLength>0)
            {
                p = richTextBox.Text.IndexOf(textBox1.Text,richTextBox.SelectionStart +1);
            }
            else
            {
                p = richTextBox.Text.IndexOf(textBox1.Text);
            }
            if(p<0)
            {
                MessageBox.Show("找不到" + textBox1.Text);
            }
            else 
            {
                richTextBox.SelectionStart = p;
                richTextBox.SelectionLength = textBox1.TextLength;
                richTextBox.Select();
            }

        }

        private void button2_Click(object sender, System.EventArgs e)
        {
            int p;
            if (richTextBox.SelectionLength > 0)
            {
                p = richTextBox.Text.IndexOf(textBox1.Text, richTextBox.SelectionStart + 1);
            }
            else
            {
                p = richTextBox.Text.IndexOf(textBox1.Text);
            }
            if (p < 0)
            {
                MessageBox.Show("找不到" + textBox1.Text);
            }
            else
            {
                richTextBox.SelectionStart = p;
                richTextBox.SelectionLength = textBox1.TextLength;
                richTextBox.Select();
                richTextBox.SelectedText = textBox2.Text;
            }
        }
        int mdx, mdy;
        private void groupBox1_MouseDown(object sender, MouseEventArgs e)
        {
            mdx = e.X;
            mdy = e.Y;
        }
        private void groupBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
   
                groupBox1.Left += e.X - mdx;
                groupBox1.Top+= e.Y - mdy;
            }

           
        }

    }
}
