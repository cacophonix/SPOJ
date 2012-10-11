/*
USER: zobayer
TASK: FACT1
ALGO: pollard rho
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Arrays;

public class Main {
	final static BigInteger ZERO = new BigInteger("0");
	final static BigInteger ONE  = new BigInteger("1");
	final static BigInteger TWO  = new BigInteger("2");
	final static SecureRandom random = new SecureRandom();
	final static InputStreamReader istream = new InputStreamReader(System.in);
	final static BufferedReader stdin = new BufferedReader(istream);

	static BigInteger[] factors = new BigInteger[64];
	static int prlen = 0;
	
	public static BigInteger rho(BigInteger N) {
		BigInteger divisor;
		BigInteger c  = new BigInteger(N.bitLength(), random);
		BigInteger x  = new BigInteger(N.bitLength(), random);
		BigInteger xx = x;

		if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;
		
		do {
			x  =  x.multiply(x).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			divisor = x.subtract(xx).gcd(N);
		} while((divisor.compareTo(ONE)) == 0);
		
		return divisor;
	}
	
	public static void factor(BigInteger N) {
		if (N.compareTo(ONE) == 0) return;
		if (N.isProbablePrime(20)) {
			factors[prlen++] = N;
			return;
		}
		BigInteger divisor = rho(N);
		factor(divisor);
		factor(N.divide(divisor));
	}

	public static void main(String[] args) throws Exception {
		String s;
		BigInteger n;
		int i, j;
		boolean first;
		while((s = stdin.readLine()) != null) {
			if(s.equals("0")) break;
			prlen = 0;
			factor(new BigInteger(s));
			Arrays.sort(factors, 0, prlen);
			for(i = 0, first = true; i < prlen; i++) {
				n = factors[i]; j = i;
				while(j < prlen && factors[j].equals(n)) j++;
				if(first) first = false;
				else System.out.print(" ");
				System.out.print(n + "^" + (j - i));
				i = j - 1;
			}
			System.out.println();
		}
	}
}