/**
 * Greed
 */
public class Greed {

    public static int greedy(int[] dice){

        int total = 0;

        int[] rolls = new int[6];
        for (int i : dice) {
            rolls[i-1] += 1;
        }
        for (int i = 0; i < rolls.length; i++) {
            while (rolls[i] > 0) {
                if (rolls[i] >= 3) {
                    total += triplePointTable(i+1);
                    rolls[i] -= 3;
                } else {
                    total += singlePointTable(i+1);
                    rolls[i]--;
                }
            }
        }
        return total;
    }

    public static int triplePointTable(int roll) {
        switch (roll) {
            case 1:
                return 1000;
            case 2:
                return 200;
            case 3:
                return 300;
            case 4:
                return 400;
            case 5:
                return 500;
            case 6:
                return 600;
            default:
                return 0;
        }
    }

    public static int singlePointTable(int roll) {
        switch (roll) {
            case 1:
                return 100;
            case 5:
                return 50;
            default:
                return 0;
        }
    }

    public static void main(String[] args) {
        System.out.println(greedy(new int[]{5,1,3,4,1}));
    }
}