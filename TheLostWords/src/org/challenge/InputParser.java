package org.challenge;

public class InputParser {
    private String[] input;

    public InputParser(String[] input) {
        this.input = input;
    }

    public char[][] transformInputIntoMatrix() {
        String[] rows = input[0].split("\n");
        char[][] output = new char[rows.length][rows[0].length()];
        for(int row = 0; row < rows.length; row++) {
            for(int column = 0; column < rows[0].length(); column++) {
                output[row][column] = rows[row].charAt(column);
            }
        }
        return output;
    }

    public String[] extractNounsToSearch() {
        String[] nounsFounded = new String[input.length - 1];
        System.arraycopy(input, 1, nounsFounded, 0, input.length - 1);
        return nounsFounded;
    }
}
