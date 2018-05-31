using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Amr;

namespace PucleGenerator
{
    public static class ImageManipulation
    {
        private static string GetPath(Image image)
        {
            string filename = Path.GetTempFileName();
            image.Save(filename, ImageFormat.Png);
            return filename;
        }

        public enum FitType
        {
            Width,
            Height,
        };
        public static Image ScaleToFit(Image image, PictureBox pictureBox)
        {
            FitType fitType = FitType.Height;
            if(image.Width > image.Height)
            {
                fitType = FitType.Width;
            }

            Image newImage = new Bitmap(1, 1);
            if(fitType == FitType.Width)
            {
                int imageOldWidth = image.Width;
                int imageNewWidth = pictureBox.Width;
                int imageNewHeight = (int)((double)pictureBox.Height * ((double)pictureBox.Width / (double)imageOldWidth));
                return Resizer.ScaleImage(GetPath(image), imageNewWidth, imageNewHeight);
            }
            else if (fitType == FitType.Height)
            {
                int imageOldHeight = image.Height;
                int imageNewWidth = (int)((double)pictureBox.Width * ((double)pictureBox.Height / (double)imageOldHeight));
                int imageNewHeight = pictureBox.Height;
                return Resizer.ScaleImage(GetPath(image), imageNewWidth, imageNewHeight);
            }
            return newImage;
        }
    }
}
