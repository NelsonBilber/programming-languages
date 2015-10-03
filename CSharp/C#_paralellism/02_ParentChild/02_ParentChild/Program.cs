using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _ParentChild
{
	class Program
	{
		static void Main(string[] args)
		{

			Task parent = new Task(
				() =>
				{
					Console.WriteLine("Parent task.");
					Task.Factory.StartNew(() => { Thread.Sleep(5000); }, 
						TaskCreationOptions.AttachedToParent);
				});

			parent.Start();

			if ((!(parent.Wait(2000)) &&
				(parent.Status == TaskStatus.WaitingForChildrenToComplete)))
			{
				Console.WriteLine("Parent completed but child not finished.");
				parent.Wait();
			}

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();

		}
	}
}