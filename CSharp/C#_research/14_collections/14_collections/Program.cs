using System;
using System.Collections;
using System.Collections.Generic;

namespace _collections
{
	public class DaysOfTheWeek : IEnumerable
	{
		private string[] days = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		public IEnumerator GetEnumerator()
		{
			for (int index = 0; index < days.Length; index++)
			{
				// Yield each day of the week. 
				yield return days[index];
			}
		}
	}

	public class Zoo : IEnumerable
	{
		// Private members. 
		private List<Animal> animals = new List<Animal>();

		// Public methods. 
		public void AddMammal(string name)
		{
			animals.Add(new Animal { Name = name, Type = Animal.TypeEnum.Mammal });
		}

		public void AddBird(string name)
		{
			animals.Add(new Animal { Name = name, Type = Animal.TypeEnum.Bird });
		}

		public IEnumerator GetEnumerator()
		{
			foreach (Animal theAnimal in animals)
			{
				yield return theAnimal.Name;
			}
		}

		// Public members. 
		public IEnumerable Mammals
		{
			get { return AnimalsForType(Animal.TypeEnum.Mammal); }
		}

		public IEnumerable Birds
		{
			get { return AnimalsForType(Animal.TypeEnum.Bird); }
		}

		// Private methods. 
		private IEnumerable AnimalsForType(Animal.TypeEnum type)
		{
			foreach (Animal theAnimal in animals)
			{
				if (theAnimal.Type == type)
				{
					yield return theAnimal.Name;
				}
			}
		}

		// Private class. 
		private class Animal
		{
			public enum TypeEnum { Bird, Mammal }

			public string Name { get; set; }
			public TypeEnum Type { get; set; }
		}
	}

	public class MyCollection: IEnumerable
	{

		int[] datum = {1,2,3};

		public IEnumerator GetEnumerator()
		{
			foreach(int i in datum)
				yield return i;
		}


	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			MyCollection c = new MyCollection ();  // we can iterate the class
			//Console.WriteLine (c.GetEnumerator());

			foreach (int i in c) {
				Console.WriteLine (i);
			}

			DaysOfTheWeek days = new DaysOfTheWeek();

			foreach (string day in days)
			{
				Console.Write(day + " ");
			}

			Zoo theZoo = new Zoo();

			theZoo.AddMammal("Whale");
			theZoo.AddMammal("Rhinoceros");
			theZoo.AddBird("Penguin");
			theZoo.AddBird("Warbler");

			foreach (string name in theZoo)
			{
				Console.Write(name + " ");
			}
			Console.WriteLine();
			// Output: Whale Rhinoceros Penguin Warbler 

			foreach (string name in theZoo.Birds)
			{
				Console.Write(name + " ");
			}
			Console.WriteLine();
			// Output: Penguin Warbler 

			foreach (string name in theZoo.Mammals)
			{
				Console.Write(name + " ");
			}
			Console.WriteLine();
		}
	}
}
