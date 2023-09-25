/* pra5.2 LCS using DP static program
 AIM: Implement a program to print the longest common subsequence for the following strings. */


public class LCS {
	 
	static int counting = 0;
	static int lcs( char[] X, char[] Y, int m, int n ) {
		int L[][] = new int[m+1][n+1];
		for (int i=0; i<=m; i++) {
			for (int j=0; j<=n; j++) {
				if (i == 0 || j == 0)
					L[i][j] = 0;
				else if (X[i-1] == Y[j-1])
					L[i][j] = L[i-1][j-1] + 1;
				else
					L[i][j] = max(L[i-1][j], L[i][j-1]);
				counting++;
			}
		}
		return L[m][n];
	}

	static int max(int a, int b) {
		return (a > b)? a : b;
	}

	public static void main(String[] args) {
		String s1[] = {
				"STONE",
				"ABCDAB",
				"AGGTABA",
				"LOGARITHM",
				"EXPONENTIAL"
		};
		String s2[] = {
				"SONATE",
				"BCDABA",
				"GXTXAYBA",
				"ALGORITHM",
				"POLYNOMIAL"
		};
		for(int i=0; i<s1.length; i++) {
			System.out.println("Length of LCS : " + lcs(s1[i].toCharArray(), s2[i].toCharArray(), s1[i].length(), s2[i].length()));
			System.out.println("Counting : " + counting + "\n");
			counting = 0;
		}
	}
}

