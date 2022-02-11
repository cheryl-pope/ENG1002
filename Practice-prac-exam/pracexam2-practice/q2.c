int values_under_100(int * numbers, int count) {
	int under_100 = 0;
	for (int i=0; i<count; i++) {
		if (numbers[i] < 100)
			under_100++;
	}
	return under_100;
}