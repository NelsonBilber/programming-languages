using System;


/* ---------------------------------------------------------------------------------
 * 
 * Abstract class vs Interfaces
 * 
 * - Abstract classes can contain implementations of methods, fields
 * contructos, ..., While interface can only contains methods method
 * and proprieties prototypes
 * - class can inherit multiple interfaces but only one class (abstract or concrete)
 * - Interface defines something can do (how it behaves) while abstract class 
 * defines what something is
 * - Interfaces implicity all members are abstract
 * --------------------------------------------------------------------------------*/


namespace _Interface
{
    interface MyInterface
	{
		 void print();		
	}

	interface IEquatable <T>: MyInterface
	{
		// implicity all members are abstract
		int serialNumber { get; set;}
		bool Equals (T obj);
	}

	public class Car: IEquatable<Car>, MyInterface
	{
		public int id { get; set;}

		public int serialNumber 
		{ 
			get { return 11;} 
			set { this.serialNumber = value; }
		}

		public bool Equals( Car c)
		{
			if (this.id == c.id) {
				return true;
			}
			return false;
		}

		public void print()
		{
			Console.Write ("Car class ....");
		}
	}

	public class MySubCar: Car
	{}

	class MainClass
	{
		public static void Main (string[] args)
		{
			// cast implicity an object to an Interface that implements
			IEquatable<Car> ic = new Car ();
			IEquatable<Car> ics = new MySubCar ();

			Console.WriteLine (ic.serialNumber);
			Console.WriteLine (ics.serialNumber);
		}
	}
}
