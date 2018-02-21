using System;
using System.Linq;
using System.Collections.Generic;

namespace C__1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Sandwich> storage = new List<Sandwich>();
            //*New sandwiches
            Sandwich sandwich1 = new Sandwich() {};
            sandwich1.AddIngridient(new Ingridient(){Name = "Pomidor", Weight = 0.12, TastinessFactor = 0.8});
            sandwich1.AddIngridient(new Ingridient(){Name = "Ser", Weight = 0.09, TastinessFactor = 1.2});
            sandwich1.AddIngridient(new Ingridient(){Name = "Maslo", Weight = 0.05, TastinessFactor = 1.4});
            sandwich1.AddIngridient(new Ingridient(){Name = "Chleb", Weight = 0.11, TastinessFactor = 1.5});
            Console.WriteLine($"{sandwich1.Owner}'s sandwich: {sandwich1.Weight}g, tastiness {sandwich1.TastinessFactor}");
            Console.ReadLine();
        }
    }
}
