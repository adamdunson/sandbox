class Problem10 {
  public static void main(String[] args) {
    ArrayList primes = new ArrayList();
    int max_val;

    if(args.length > 0) {
      try {
        max_val = Integer.parseInt(args[0]);
      } catch(NumberFormatException e) {
        System.exit(1);
      }
    } else {
      System.exit(1);
    }

    int i = 0;
    while(i < 2000000) {
      if(isPrime(i, primes)) {
        primes.add(i);
      }
    }

    System.out.println(addPrimes(primes));
  }
}
