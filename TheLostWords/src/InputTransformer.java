import java.util.List;

public class InputTransformer {
    private final List<String> input;

    public InputTransformer(List<String> input) {
        this.input = input;
    }

    public char[][] transformInputIntoMatrix() {
        String[] rows = input.get(0).replace("\"", "").replace("\\n", " ").split(" ");
        char[][] output = new char[rows.length][rows[0].length()];
        for(int row = 0; row < rows.length; row++) {
            for(int column = 0; column < rows[0].length(); column++) {
                output[row][column] = rows[row].charAt(column);
            }
        }
        return output;
    }

    public String[] nounsToSearch() {
        String[] nounsFounded = new String[input.size() - 1];
        for(int i = 1; i < input.size(); i++)
            nounsFounded[i - 1] = input.get(i).replace("\"", "");
        return nounsFounded;
    }
}
