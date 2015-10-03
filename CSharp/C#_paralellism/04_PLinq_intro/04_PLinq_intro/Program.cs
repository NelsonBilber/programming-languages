using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Publisher
{
	class Book
	{
		public string Publisher { get; set; }
		public string First { get; set; }
		public string Last { get; set; }
		public string Title { get; set; }
		public string ISBN { get; set; }
	}

	class Program
	{
		static void Main(string[] args)
		{
			var books = new[] {new Book{Publisher="Lucerne Press",
					First="David",
					Last="Hamilton",
					Title="David Hamilton Book",
					ISBN="ISBN Number" },
				new Book{Publisher="Lucerne Press",
					First="Stefan",
					Last="Hesse",
					Title="Stefan Hesse Book",
					ISBN="ISBN Number"},
				new Book{Publisher="Lucerne Press",
					First="Mike",
					Last="Ray",
					Title="Mike Ray Book",
					ISBN="ISBN Number"},
				new Book{Publisher="Lucerne Press",
					First="Bento",
					Last="Nuno",
					Title="Bento Nuno Book",
					ISBN="ISBN Number"}};

			var titles=from book in books.AsParallel() where book.Publisher=="Lucerne Press" 
			            orderby book.Title select book;

			foreach(Book book in titles)
			{
				Console.WriteLine("{0} {1}: {2}", book.First, book.Last, book.Title);
			}

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();
		}
	}
}
