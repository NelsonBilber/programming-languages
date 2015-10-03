using System;
using System.Collections.Generic;

namespace _generics
{
	public class GenericList<T>
	{
		private class Node
		{
			public Node(T t)
			{
				next = null;
				data = t;
			}

			private Node next;
			public Node Next
			{
				get {  return next;}
				set { next = value;}
			}

			private T data;

			public T Data 
			{
					get { return data; }
					set { data = value; }
				}

		}

		private Node head;

		public GenericList()
		{
			head = null;
		}

		public void AddHead(T t)
		{
			Node n = new Node (t);
			n.Next = head;
			head = n;
		}

		public IEnumerator<T> GetEnumerator()
		{
			Node current = head;

			while (current != null) {
				yield return current.Data;
				current = current.Next;
			}
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			GenericList<int> list = new GenericList<int> ();

			for (int i = 0; i < 10; i++) {
				list.AddHead (i);
			}

			foreach (int i  in list) {
				Console.Write (i + " ");
			}

			Console.Write ("\n");

			GenericList<string> list2 = new GenericList<string> ();

			for (int i = 0; i < 10; i++) {
				string si = i.ToString ();
				si += " string value ";
				list2.AddHead (si);
			}

			foreach (string i in list2) {
				Console.Write (i + " \n");
			}

		}
	}
}
