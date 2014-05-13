import java.math.BigInteger;

class Problem20 {
  public static BigInteger factorial(int n) {
    if(n == 0) {
      return BigInteger.ONE;
    }
    return BigInteger.valueOf(n).multiply(factorial(n - 1));
  }

  private static int addDigits(BigInteger bigint) {
    String temp = bigint.toString();
    int sum = 0;

    for(int i = 0; i < temp.length(); i++) {
      sum += temp.charAt(i) - '0';
    }

    return sum;
  }

  public static void main(String[] args) {
    BigInteger result = BigInteger.ONE;

    if(args.length > 0) {
      try {
        result = factorial(Integer.parseInt(args[0]));
      } catch(NumberFormatException e) {
        System.exit(1);
      }
    } else {
      System.exit(1);
    }

    System.out.println(args[0] + "! = " + result.toString());

    System.out.println("Final Result: " + addDigits(result));
  }
}
