using System;

namespace _events
{


	public class ValueChangedEventArgs: EventArgs
	{
		public readonly int myvalue;

		public ValueChangedEventArgs(int myvalue)
		{
			this.myvalue = myvalue;
			Console.Write("Fires event !!");
		}

	}

	public class GeneralClass
	{
		int xvalue;

		public event EventHandler<ValueChangedEventArgs> ValueChanged;

		protected virtual void OnValueChanged(ValueChangedEventArgs e)
		{
			if (ValueChanged != null) {
				ValueChanged (this, e);
			}
		}


		public int XValue 
		{
			get
			{
				return xvalue;
			}

			set 
			{
				xvalue = value;
				OnValueChanged (new ValueChangedEventArgs (xvalue));
				
			}
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			GeneralClass g = new GeneralClass ();
			g.XValue = 100;
		}
	}
}
