using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Learning
{
    public class Game
    {
        public virtual void Menu()
        {
            Console.WriteLine("Default menu");
        }
    }

    public class TicTacToe:Game
    {
        public override void Menu()
        {
            Console.WriteLine("Tic tac toe menu");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TicTacToe test = new TicTacToe();
            test.Menu();
        }
    }
}
