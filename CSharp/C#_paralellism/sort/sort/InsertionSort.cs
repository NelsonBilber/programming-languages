using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SortParallel
{
    public partial class SortAlgorithms
    {
        public static void InsertionSort(List<int> sortedList)
        {
            int count = sortedList.Count;
            int currentLocation, currentValue, insertionLocation;
            sortedList.Insert(0, 0);

            for (int location = 1; location < count + 1; ++location)
            {
                currentLocation = location;
                insertionLocation = location - 1;
                currentValue = sortedList[currentLocation];
                while (sortedList[insertionLocation] > currentValue)
                {
                    sortedList[currentLocation] = sortedList[insertionLocation];
                    --currentLocation;
                    --insertionLocation;
                }
                sortedList[currentLocation] = currentValue;
            }
            sortedList.Remove(0);
        }
    }
}
