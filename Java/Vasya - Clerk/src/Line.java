import java.util.Comparator;
import java.util.SortedMap;
import java.util.TreeMap;

/**
 * Line
 */
public class Line {

    public static String Tickets(int[] peopleInLine) {

        final String TRUE = "YES";
        final String FALSE = "NO";

        SortedMap<Integer, Integer> map = new TreeMap<>(Comparator.reverseOrder());

        for (int i : peopleInLine) {
            map.computeIfPresent(i, (key, val) -> val + 1);
            map.putIfAbsent(i, 1);

            int changeDue = i - 25;

            while (changeDue > 0 && !map.isEmpty()) {
                if (map.tailMap(changeDue).size() == 0) {
                    return FALSE;
                }
                int value = map.tailMap(changeDue).firstKey();
                changeDue -= value;
                map.put(value, map.get(value) - 1);
                if (map.get(value) == 0) {
                    map.remove(value);
                }
            }
        }
        return TRUE;
    }

    public static String TicketsV2(int[] peopleInLine){
        int bill25 = 0, bill50 = 0;
        for (int payment : peopleInLine){
            if(payment==25){
                bill25++;
            } else if(payment==50){
                bill25--;
                bill50++;
            } else if(payment==100){
                if(bill50>0){
                    bill50--;
                    bill25--;
                } else{
                    bill25-=3;
                }
            }
            if(bill25<0 || bill50 <0){
                return "NO";
            }
        }
        return "YES";
    }

    public static void main(String[] args) {
        int[] input = {25, 25, 50, 50, 100};
        long startTime = System.nanoTime();
        System.out.println(TicketsV2(input));
        long stopTime = System.nanoTime();
        System.out.println("Time: " + (stopTime - startTime) + "ns");
    }

}