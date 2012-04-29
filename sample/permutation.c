Explanation 1.
---------------------------------------------
void RecursivePermute(char str[], int k) {
int j;
// Base-case: All fixed, so print str.

if (k == strlen(str))
printf("%s\n", str);

else {
// Try each letter in spot j.

for (j=k; j<strlen(str); j++) {
// Place next letter in spot k.
ExchangeCharacters(str, k, j);
// Print all with spot k fixed.
RecursivePermute(str, k+1);
// Put the old char back.
ExchangeCharacters(str, j, k);
}

}

}
--------------------------------------------
Another explanation

void perm (int v[], int n, int i) {

	/* this function generates the permutations of the array
	 * from element i to element n-1
	 */
	int	j;

	/* if we are at the end of the array, we have one permutation
	 * we can use (here we print it; you could as easily hand the
	 * array off to some other function that uses it for something
	 */
	if (i == n) {
		for (j=0; j<n; j++) printf ("%d ", v[j]);
		printf ("\n");
	} else
		/* recursively explore the permutations starting
		 * at index i going through index n-1
		 */
		for (j=i; j<n; j++) {

			/* try the array with i and j switched */

			swap (v, i, j);
			perm (v, n, i+1);

			/* swap them back the way they were */

			swap (v, i, j);
		}
}
