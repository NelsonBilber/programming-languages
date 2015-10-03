using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SortParallel
{
    public partial class SortAlgorithms
    {
        public static void BubbleSort(List<int> sortedList)
        {
            int count = sortedList.Count;
            int temporary;

            for (int iteration = 0; iteration < count; ++iteration)
            {
                for (int index = 0; index + 1 < count; ++index)
                {
                    if (sortedList[index] > sortedList[index + 1])
                    {
                        temporary = sortedList[index];
                        sortedList[index] = sortedList[index + 1];
                        sortedList[index + 1] = temporary;
                    }
                }
            }
        }
    }
}
