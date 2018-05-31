using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoloLearn_Polymorphism
{
    public interface ILiving
    {
        void Breathe();
    }

    public abstract class AbstractTest
    {
        public abstract void AbstractMethod();
        public abstract string AbstractProperty { get; set; }
    }

    public class Animal:AbstractTest, ILiving
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public int Weight { get; set; }
        public string Sound { get; set; }

        public void Breathe()
        {

        }

        public override string AbstractProperty { get; set; }

        public override void AbstractMethod()
        {
            throw new NotImplementedException();
        }

        public Animal()
        {
            Console.WriteLine("Animal created.");
        }

        protected void PoopHandler()
        {
            Console.WriteLine("prrt");
        }

        public virtual void MakeSound()
        {
            Console.WriteLine(Sound);
        }

        ~Animal()
        {
            Console.WriteLine("Animal deleted");
        }
    }

    public sealed class Dog:Animal
    {
        public string Owner { get; set; }

        public Dog()
        {

        }

        public void MakePoop()
        {
            base.PoopHandler();
        }

        public override void MakeSound()
        {
            Console.Write("Arrr ");
            base.MakeSound();
        }
    }
}
