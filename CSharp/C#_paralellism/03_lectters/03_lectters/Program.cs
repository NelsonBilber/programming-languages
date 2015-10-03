using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Letters
{
	class Program
	{
		static void Main(string[] args)
		{
			Tuple<string, int>[] tuples = new Tuple<string, int>[] {
				new Tuple<string, int>("a", 3),
				new Tuple<string, int>("b", 2),
				new Tuple<string, int>("b", 5) };

			MapReduce<string, int> letters = new MapReduce<string, int>(tuples);
			IEnumerable<Tuple<string, int>> newmap;

			letters.Map<string, int>((input) =>
				{
					return new Tuple<string, int>[] { new Tuple<string, int>(input.Item1, input.Item2 * input.Item2) };
				}, out newmap);

			IEnumerable<Tuple<string, int>> reduction = letters.Reduce<string, int>(newmap, (key, values) =>
				{
					int total = 0;
					foreach (var item in values)
					{
						total += item;
					}
					return total;
				});

			foreach (var item in reduction)
			{
				Console.WriteLine("{0} = {1}", item.Item1, item.Item2);
			}

			Console.WriteLine("Press enter to exit.");
			Console.ReadLine();
		}

	}

}
