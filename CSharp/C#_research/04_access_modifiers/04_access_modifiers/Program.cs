using System;


/* --------------------------------------
 * 
 * Access Modifiers
 * 
 * public
 * privatie
 * protected
 * internal (same assembly)
 * 
 * -------------------------------------*/


namespace _access_modifiers
{
	public abstract class A
	{

		public abstract void DoWork(int i);
		public abstract void DoWork2(int i);
	}

	public  sealed class D: A // class D cannot have subclass and cannot be abstract
	{
		public override void DoWork(int i) {}
		public sealed override void DoWork2(int i) {} //cannot be ovverided by subclass
	}

	struct MyStruct
	{
		void test(){} // private ny default
		public void test2() {} // public
	}

	class PrivateClass
	{
		
	}

	public class MyClass
	{
		public string name_public { get; set;}
		protected string name_protected { get; set;}
		private string name_private { get; set;} 
		internal string name_internal { get; set;}

		void tt(){} //private by default
	}

	public class MySubClass : MyClass
	{
		public string sub_name_public { get; set;}
		protected string sub_name_protected { get; set;}
		private string sub_name_private { get; set;} 
		internal string sub_name_internal { get; set;}

		public void ttt() 
		{
			name_protected = "x";
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			MyClass c = new MyClass ();
			c.name_internal = "x";
			c.name_public = "xx";

			MySubClass sc = new MySubClass ();
			sc.ttt (); // access proteced modifier

			PrivateClass pc = new PrivateClass ();
			pc.GetHashCode ();

			MyStruct st = new MyStruct ();
			st.test2 ();
		}
	}
}
