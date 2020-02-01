import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * EnoughIsEnough
 */
public class EnoughIsEnough {

    public static int[] deleteNth(int[] elements, int maxOccurrences) {

        ArrayList<Integer> output = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        
        if (maxOccurrences == 0){
            return new int[0];
        }

		for (int i : elements) {
            if (!map.containsKey(i)){
                map.put(Integer.valueOf(i), Integer.valueOf(1));
                output.add(i);
            }else if (map.containsKey(i)){
                if (map.get(i) < maxOccurrences){
                    map.put(Integer.valueOf(i), map.get(i)+1);
                    output.add(i);
                }
            }
        }
        int[] testOutput = new int[output.size()];
        int index = 0;
        for (int i : output) {
            testOutput[index] = i;
            index ++;
        }
		return testOutput;
	}

    public static void main(String[] args) {
        int[] input = {1, 1, 2, 2, 2, 3, 4, 5};
        int[] output = deleteNth(input, 3);
        System.out.println(Arrays.toString(output));
    }
};