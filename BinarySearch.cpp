int binarySearch(int a[], int l, int r, int val)
{
	if (l < r)
	{	
		int mid = (l + r) / 2;
		if (a[mid] == val)
		{
			return mid;
		}
		if (a[mid] > val)
		{
			return binarySearch(a, l, mid - 1, val);
		}
		if (a[mid] < val)
		{
			return binarySearch(a, mid + 1, r, val);
		}
	}

	return -1;

}
