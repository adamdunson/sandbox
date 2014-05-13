import java.math.BigInteger;
import java.io.IOException;

class Problem25 {
  public static void main(String[] args) {
    BigInteger fib1 = BigInteger.ONE;
    BigInteger fib2 = BigInteger.ONE;
    boolean swap = true;
    int cnt = 2;

    while(true) {
      if(swap) {
        fib1 = fib1.add(fib2);
        cnt++;
        if(fib1.toString().length() == 1000) {
          System.out.println(cnt);
          break;
        }
        swap = false;
      } else {
        fib2 = fib2.add(fib1);
        cnt++;
        if(fib2.toString().length() == 1000) {
          System.out.println(cnt);
          break;
        }
        swap = true;
      }
    }
  }
}
