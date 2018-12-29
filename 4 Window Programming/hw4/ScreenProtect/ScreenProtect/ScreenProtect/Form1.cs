using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScreenProtect
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        Random R = new Random();

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = DateTime.Now.ToString();
            label1.Left -= 10;
            if (label1.Right < 0)
            {
                label1.Left = this.ClientSize.Width;
                label1.Top = R.Next(this.Height - label1.Height);
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            int D = R.Next(this.Height);
            int X = R.Next(this.Width - D);
            int Y = R.Next(this.Height - D);
            Bitmap bg = new Bitmap(this.Width, this.Height);
            Graphics g = Graphics.FromImage(bg);
            Color C = Color.FromArgb(R.Next(256), R.Next(256), R.Next(256));
            SolidBrush B = new SolidBrush(C);
            g.FillEllipse(B, X, Y, D, D);
            this.BackgroundImage = bg;
        }

        int curP = 0;
        private void timer3_Tick(object sender, EventArgs e)
        {
            curP += 1;
            if (curP > 3) curP = 1;
            switch (curP)
            {
                case 1 :
                    this.BackgroundImage = Properties.Resources.P1;
                    break;
                case 2 :
                    this.BackgroundImage = Properties.Resources.P2;
                    break;
                case 3 :
                    this.BackgroundImage = Properties.Resources.P3;
                    break;
            }
        }
    }
}
