/**
 * Kata
 */
public class Kata {

    public static double findUniq(double arr[]) {
        double first = arr[0];
        if (first != arr[1]){
            if (first != arr[2]) {
                return first;
            } else {
                return arr[1];
            }
        }
        for (int i = 1; i < arr.length; i++) {
            if (first != arr[i]) {
                return arr[i];
            }
        }
        return -1;
      }

    public static void main(String[] args) {
        double[] arr =  {1, 1, 1, 2, 1, 1};
        System.out.println(findUniq(arr));
    }
}