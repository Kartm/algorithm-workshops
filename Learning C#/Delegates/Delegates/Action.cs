using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Delegates
{
    class Action
    {
        public EventHandler ActionDone;

        public void DoAction()
        {
            Console.WriteLine("Starting action");
            Thread.Sleep(1000);
            OnActionDone();
        }

        protected virtual void OnActionDone()
        {
            /*if (ActionDone != null)
            {
                ActionDone(this, EventArgs.Empty);
            }*/
            
            ActionDone.Invoke(this, EventArgs.Empty);
        }
    }
}
