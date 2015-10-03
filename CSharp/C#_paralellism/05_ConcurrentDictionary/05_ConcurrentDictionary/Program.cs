using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections.Concurrent;
using System.Threading.Tasks;

namespace Example
{
	class Program
	{
		static void Main(string[] args)
		{
			var numbers = new int[] { 1, 2, 4, 2, 3, 1, 2 };

			var collection = new ConcurrentDictionary<int, int>();
			Parallel.ForEach(numbers, (number) =>
				{
					collection.AddOrUpdate(number, 1, (key, value) =>
						{
							return ++value;
						});
				});

			foreach (var entry in collection)
			{
				Console.WriteLine("Key: {0} Count: {1}", entry.Key, entry.Value);
			}
			Console.WriteLine("Press enter to exit");
			Console.ReadLine();
		}
	}
}
