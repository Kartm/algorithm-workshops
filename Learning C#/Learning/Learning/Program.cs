using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Learning
{
    public interface ITest
    {
        void TestRequiredMethod();
    }

    public class Part
    {
        public Part()
        {

        }
        public void TestMethod()
        {
            Console.WriteLine("TestMethod");
        }
    }

    public class PartBig:Part, ITest
    {
        public PartBig()
        {

        }

        public void TestRequiredMethod()
        {
            Console.WriteLine("Required method");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            PartBig test = new PartBig();
            test.TestMethod();
        }
    }
}
