using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoloLearn_Polymorphism
{
    class Program
    {
        static void Main(string[] args)
        {
            Animal cricket = new Animal() {Name = "Twwrrr", Age = 1, Weight = 2, Sound = "TCHCHCH"};
            cricket.MakeSound();

            Dog doggie = new Dog() { Name = "Azor", Age = 1, Weight = 42, Sound = "HAU", Owner = "No Owner" };
            doggie.MakeSound();
            doggie.MakePoop();

            Animal doggie2 = new Dog();
            

            Console.Read();
        }
    }
}
