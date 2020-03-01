/**
 * Keypad
 */
public class Keypad {

    public static int presses(String phrase) {
        int presses = 0;
        String[] layout =   {"1",    "abc2", "def3",
                             "ghi4", "jkl5", "mno6",
                             "pqrs7","tuv8", "wxyz9",
                             "*",    " 0",   "#"};
        for (char character : phrase.toLowerCase().toCharArray()) {
            for (String button : layout) {
                presses += button.indexOf(character) + 1;
            }
        }
        return presses;
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();
        System.out.println(presses("LOL"));
        long endTime   = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println(totalTime);
    }
}