using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _PriceIncrease
{
	class MainClass
	{
		static int[] inventoryList = new int [] {100, 750, 400, 75, 900, 975, 275, 
			750, 600, 125, 300};


		public static void Main (string[] args)
		{
			Parallel.For( 0, inventoryList.Length, (index) =>
				{
					var value = inventoryList[index];
					if (value > 500)
					{
						inventoryList[index] = (int)(value* .8);
					}
					else
					{
						inventoryList[index] = (int)(value* .9);
					}

					Console.WriteLine("Item {0,4} Price: {1, 7:f}",
						index, inventoryList[index]);
				});

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();

		}
	}
}
