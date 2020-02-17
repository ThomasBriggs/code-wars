import java.util.HashMap;
import java.util.Map;

/**
 * FindOdd
 */
public class FindOdd {

    public static int findIt(int[] a) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : a) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        for (Integer i : map.keySet()) {
            if (map.get(i) % 2 == 1) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int i = findIt(new int[]{20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5});
        System.out.println(i);
    }
}