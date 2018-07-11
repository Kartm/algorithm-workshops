using System;
using OpenweatherTest;

namespace OpenweatherTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter city name: ");
            string cityName = Console.ReadLine();
            System.Console.WriteLine("Getting " + cityName + " forecast...");
            //System.Console.WriteLine(Weather.GetJsonWeather(cityName));
            Weather.Display(Weather.GetJsonWeather(cityName));
        }
    }
}
