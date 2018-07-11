using System;
using Gtk;

namespace Todoline
{
    class MainClass
    {
		private static void CreateTimeline(MainWindow win)
		{
			int daysInMonth = DateTime.DaysInMonth(DateTime.Now.Year, DateTime.Now.Month);
            
		}

        public static void Main(string[] args)
        {
            Application.Init();
            MainWindow win = new MainWindow();
			win.ShowAll();
			CreateTimeline(win);
            Application.Run();
        }
    }
}
