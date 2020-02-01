/**
 * DRoot
 */
public class DRoot {

    public static int digital_root(int n) {
        int total = 0;
        int length = String.valueOf(n).length();
        while (length > 1) {
            char[] ints = String.valueOf(n).toCharArray();
            for (char digit : ints) {
                total += Character.getNumericValue(digit);
            }
            n = total;
            total = 0;
            length = String.valueOf(n).length();
        }
        return n;
    }

    public static int digital_rootv2(int n) {
        while(n > 9){
          n = n/10 + n % 10;
          System.out.println(n);
          }
        return(n);
      }

    public static void main(String[] args) {
        System.out.println(digital_rootv2(256));
    }
}