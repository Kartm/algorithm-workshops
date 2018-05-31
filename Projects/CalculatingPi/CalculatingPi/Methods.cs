using System;
using System.Collections.Generic;
using System.Text;

namespace CalculatingPi
{
    /*
    This class contains the methods to calculate Pi.
    */
    public static class Methods
    {
        //infinite series

        public static double GLSeries(double precision)//Gregory-Leibniz Series
        {
            /*
            An example:
            PI/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
             * */
            double result = 0D; //it's PI/4
            bool add = true;
            double denominator = 1;
            for(double i = 1; i <= precision; i++)
            {
                result = (add) ? result += 1/denominator : result -= 1/denominator;
                add = !add;
                denominator += 2;
            }

            return result * 4D;
        }

        public static double Polygons(double precision)
        {
            //We're starting with an square with edge length sqrt(2)
            //So it's a polygon with 4 sides
            double polygonSquaredEdge = 2D;
            double polygonEdges = 4D;
            for(double i = 0; i < precision; i++)
            {
                polygonSquaredEdge = 2 - 2 * Math.Sqrt(1 - (polygonSquaredEdge) / 4);
                polygonEdges *= 2;
            }
            return Math.Sqrt(polygonSquaredEdge) * polygonEdges / 2;
        }
    }
}
