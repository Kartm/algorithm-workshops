using System;
using System.Net;
using Newtonsoft.Json;

namespace OpenweatherTest
{
    public static class Weather
    {
        private static string apiKey = "bba7e44c29932bbdbbfd7eb2fd77b5a5";
        
        private static string BuildUrl(string cityName)
        {
            return $"http://api.openweathermap.org/data/2.5/forecast?q={cityName}&APPID={apiKey}&units=metric";
        }

        //todo - caching the data
        public static dynamic GetJsonWeather(string cityName)
        {
            string response;
            using(var client = new WebClient())
            {
                response = client.DownloadString(BuildUrl(cityName));
            }
            return JsonConvert.DeserializeObject(response);
        }

        private static string EpochToString(int epoch)
        {
            DateTimeOffset dateTimeOffset = DateTimeOffset.FromUnixTimeSeconds(epoch);
            DateTime dateTime = dateTimeOffset.LocalDateTime;
            return dateTime.ToString("dd-MM-yyyy HH:mm");
        }
        
        public static void Display(dynamic weatherData)
        {
            foreach(var entry in weatherData.list)
            {
                System.Console.WriteLine(EpochToString(Int32.Parse(entry.dt.ToString())) + ", " + entry.main.temp + "°C, " + entry.weather[0].description);
            }
        }
    }
}