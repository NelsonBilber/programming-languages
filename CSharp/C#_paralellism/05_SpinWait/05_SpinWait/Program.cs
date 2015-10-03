using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace SpinWait
{
	class Program
	{
		static void DoSomething() { Console.WriteLine ("Do something");}

		static void Main(string[] args)
		{
			var slock = new SpinLock();
			bool taken = false;
			try
			{
				slock.Enter(ref taken);
				DoSomething();
			}
			finally
			{
				if (taken) slock.Exit();
			}
		}
	}
}
