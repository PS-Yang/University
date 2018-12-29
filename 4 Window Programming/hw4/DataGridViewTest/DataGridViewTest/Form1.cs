using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DataGridViewTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            DataGridViewRowCollection rows = dataGridView1.Rows;
            rows.Add(new Object[] { "小明", "男", "001" });
            rows.Add(new Object[] { "小花", "女", "002" });
            rows.Add(new Object[] { "小宇", "男", "003" });
            rows.Add(new Object[] { "小智", "男", "004" });
        }
    }
}
