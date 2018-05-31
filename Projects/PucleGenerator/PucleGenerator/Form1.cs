using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static PucleGenerator.ImageManipulation;
using static PucleGenerator.Algorithms;

namespace PucleGenerator
{
    public partial class Form1 : Form
    {
        Image image, newImage;
        public Form1()
        {
            InitializeComponent();
            Console.WriteLine(GetAllDividers(20, 60));
        }

        private void SetComboBoxAmount(int width, int height)
        {

        }

        private void horizontalTrackBar_Scroll(object sender, EventArgs e)
        {
            horizontalLabel.Text = "Horizontal puzzles: " + horizontalTrackBar.Value.ToString();
        }

        private void verticalTrackBar_Scroll(object sender, EventArgs e)
        {
            verticalLabel.Text = "Vertical puzzles: " + verticalTrackBar.Value.ToString();
        }

        private void button_openImageFile(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "Image Files|*.jpg;*.png;*.jpeg";
            if(dialog.ShowDialog() == DialogResult.OK)
            {
                string path = dialog.FileName;
                image = Image.FromFile(path);
                Console.WriteLine("Path to image: {0}", path);
                newImage = ScaleToFit(image, pictureBox);
                pictureBox.Image = newImage;
                
            }
            puclarizeButton.Enabled = true;
            settingsBox.Enabled = true;
            exportButtton.Enabled = true;
            SetComboBoxAmount(image.Width, image.Height);
        }
    }
}
