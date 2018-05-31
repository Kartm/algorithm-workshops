using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Delegates
{
    class Program
    {
        public delegate int TestDelegate(int x);

        static int Function1(int x)
        {
            int value = x % 2;
            Console.WriteLine("Function 1: {0}", value);
            return value;
        }

        static int Function2(int x)
        {
            int value = (x + 1) / 4;
            Console.WriteLine("Function 2: {0}", value);
            return value;
        }

        static void Main(string[] args)
        {
            var action = new Action();
            var log = new Log();
            action.ActionDone += log.OnActionDone;
            action.DoAction();

            TestDelegate testDel = Function1;
            Console.WriteLine("TestDel = {0}", testDel.Invoke(4));
            testDel += Function2;
            Console.WriteLine("TestDel = {0}", testDel.Invoke(4));
            testDel.Invoke(4);
            DelegateAsParameter(1, 2, testDel);

            TestDelegate anonymousMethod = delegate (int x)
            {
                Console.WriteLine(x);
                return x;
            };
            Console.WriteLine("{0}", anonymousMethod(4));
            Console.Read();
        }

        static void DelegateAsParameter(int a, int b, TestDelegate testDel)
        {
            Console.WriteLine("{0} - {1}", a + b, testDel(a + b));
        }
    }
}
