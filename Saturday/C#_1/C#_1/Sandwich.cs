using System.Collections.Generic;
namespace C__1
{
    public class Sandwich
    {
        public double Weight { get; set; }
        public double TastinessFactor { get; set; }
        public string Owner { get; set; }
        public List<Ingridient> ingridients { get; set; }
        
        public Sandwich()
        {
            TastinessFactor = 1;
            ingridients = new List<Ingridient>();
        }

        public double GetWeight()
        {
            return Weight;
        }

        public double GetTastinessFactor()
        {
            return TastinessFactor;
        }

        public void AddIngridient(Ingridient ingridient)
        {
            ingridients.Add(ingridient);
            Weight += ingridient.Weight;
            TastinessFactor *= ingridient.TastinessFactor;
            System.Console.WriteLine("Added {0} to {1}'s sandwich. ", ingridient.Name, Owner);
        }

    }

    public class Ingridient
    {
        public double Weight { get; set; }
        public string Name { get; set; }
        public double TastinessFactor { get; set; }
    }
}
