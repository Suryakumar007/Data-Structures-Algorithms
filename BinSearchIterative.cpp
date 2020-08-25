int binarySearchIterative(int a[], int l, int r, int val)
{
	int mid;

	while (l <= r) 
	{
		mid = (l + r) / 2;

		if (a[mid] == val)
			return mid;

		else if (a[mid] < val)
			l = mid + 1;

		else if (a[mid] > val)
			r = mid - 1;
	}

	return -1;

}
