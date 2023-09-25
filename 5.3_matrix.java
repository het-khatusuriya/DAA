class MatrixChainMultiplication {
	static int counting = 0;
	static int key[][];

	static int MatrixChainOrder(int p[], int n)
	{
		int mul[][] = new int[n][n];
		key = new int[n][n];
		int i, j, k, L, q;

		for (i = 1; i < n; i++)
			mul[i][i] = 0;
		for (L = 2; L < n; L++) {
			for (i = 1; i < n - L + 1; i++) {
				j = i + L - 1;
				
				if (j == n)
					continue;
				mul[i][j] = Integer.MAX_VALUE;
				key[i][j] = 0;
				
				for (k = i; k <= j - 1; k++) {
					q = mul[i][k] + mul[k + 1][j] + p[i - 1] * p[k] * p[j];
					counting++;
					
					if (q < mul[i][j]) {
						mul[i][j] = q;
						key[i][j] = k;
					}
				}
			}
		}
		printMultiplication(1, n-1);
		System.out.println();
		return mul[1][n - 1];
	}

	public static void main(String args[]) {
		int arr[][] = {
				{15, 5, 10, 20},
				{35, 15, 5, 10, 20},
				{30, 35, 15, 5, 10, 20},
				{30, 35, 15, 5, 10, 20, 25},
				{30, 35, 15, 5, 10, 20, 25, 10}
		};
		for(int i=0; i< arr.length; i++) {
			System.out.println("Minimum Multiplications : " + MatrixChainOrder(arr[i], arr[i].length));
			System.out.println("Counting : " + counting  + "\n");
			counting = 0;
		}
	}
	
	static void printMultiplication(int i, int j) {
		if(i == j)
			System.out.print("A" + i);
		else {
			System.out.print("(");
			printMultiplication(i, key[i][j]);
			System.out.print(" * ");
			printMultiplication(key[i][j] + 1, j);
			System.out.print(")");
		}
	}
}

