
import java.util.*;

class MergeSort
{
    public static void printArray(int[] list)
    {
	for (int i = 0; i < list.length - 1; i++)
	    System.out.print(list[i] + ", ");
	System.out.println(list[list.length - 1]);
    }

    public static void sort(int[] list)
    {
	if (list.length > 2)
	{
	    // split
	    int halfSize = list.length / 2;
	    int[] a = new int[halfSize];
	    int[] b = new int[halfSize + list.length % 2];
	    for (int i = 0; i < halfSize; i++)
	    {
		a[i] = list[i];
		b[i] = list[i + halfSize];
	    }
	    if (list.length % 2 == 1)
		b[b.length - 1] = list[list.length - 1];
	    // sort
	    sort(a);
	    sort(b);
	    // merge
	    int aCounter = 0;
	    int bCounter = 0;
	    int listCounter = 0;
	    while ((aCounter < a.length) || (bCounter < b.length))
	    {
		if (aCounter >= a.length)
		{
		    while (bCounter < b.length)
			list[listCounter++] = b[bCounter++];
		    break;
		}
		else if (bCounter >= b.length)
		{
		    while (aCounter < a.length)
			list[listCounter++] = a[aCounter++];
		    break;
		}
		else if (a[aCounter] < b[bCounter])
		    list[listCounter++] = a[aCounter++];
		else
		    list[listCounter++] = b[bCounter++];
	    }
	}
	else if (list.length == 2)
	    if (list[0] > list[1])
	    {
		int temp = list[0];
		list[0] = list[1];
		list[1] = temp;
	    }
    }

    public static void main(String[] args)
    {
	int size = Integer.parseInt(args[0]);
	int[] list = new int[size];
	System.out.print("Generating Numbers");
	int frac = size / 10;
	for (int i = 0; i < size; i++)
	{
	    if (i % frac == 0) System.out.print(".");
	    int n = (int)(Math.random() * 100000);
	    list[i] = n;
	}
	System.out.println("\nSorting");
	long startTime = System.currentTimeMillis();
	//int[] list = {1, 3, 2, 5, 4, 7, 6, 9, 8};
	sort(list);
	long stopTime = System.currentTimeMillis();
	System.out.println("Done!");
	System.out.println("Sort finished sorting " + size + " elements in " + (stopTime - startTime) + " milliseconds");
	//printArray(list);
    }
}
