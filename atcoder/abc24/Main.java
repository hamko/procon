import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a = sc.nextBigInteger();
        BigInteger b = sc.nextBigInteger();
        BigInteger c = sc.nextBigInteger();
        

        BigInteger j = 
            b.multiply(c.subtract(a)).
            divide(a.multiply(c).add(a.multiply(b)).subtract(b.multiply(c)));
        BigInteger i = j.multiply(b).subtract(c).add(b).divide(c);

        System.out.println(i + " " + j);
        sc.close();
    }

}
