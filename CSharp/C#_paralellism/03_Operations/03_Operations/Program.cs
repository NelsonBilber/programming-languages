using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

namespace _Operations
{
	class MainClass
	{
		static void Operation(){
		
			Thread.SpinWait (int.MaxValue);	
		}


		public static void Main (string[] args)
		{
			for (int i = 0; i < 100; i++) {
			
				Operation ();
			}
		}
	}
}
