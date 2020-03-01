public class DnaStrand {
    public static String makeComplement(String dna) {
        String output = "";
        String at = "at";
        String cg = "cg";
        for (char cell : dna.toLowerCase().toCharArray()) {
            if (cell == 'a' || cell == 't') output += at.charAt((at.indexOf(cell) +1) %2);
            else output += cg.charAt((cg.indexOf(cell) +1) %2);
        }
        return output.toUpperCase();
    }

    public static void main(String[] args) {
        System.out.println(makeComplement("TAACG"));
    }
}