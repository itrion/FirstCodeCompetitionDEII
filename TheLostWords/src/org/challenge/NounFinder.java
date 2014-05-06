package org.challenge;

public class NounFinder {
    private char[][] input;

    public NounFinder(char[][] input) {
        this.input = input;
    }

    public NounCoordinates doAVerticalSearch(String noun) {
        for(int column = 0; column < input[0].length; column++)
            for(int row = 0; row < input.length - noun.length() + 1; row++)
                if(isNounContainedInThisColumnFromThisRow(noun, column, row))
                    return new NounCoordinates(new Coordinate(row, column), new Coordinate(row + noun.length() - 1, column));
        return new NounCoordinates(new Coordinate(-1, -1), new Coordinate(-1, -1));
    }

    private boolean isNounContainedInThisColumnFromThisRow(String noun, int column, int row) {
        int nounIndex = 0;
        for(int inputSubIndex = row; inputSubIndex < row + noun.length(); inputSubIndex++)
            if(input[inputSubIndex][column] != noun.charAt(nounIndex++)) return false;
        return true;
    }

    public NounCoordinates doAReverseVerticalSearch(String noun) {
        return reverseNounCoordinates(doAVerticalSearch(new StringBuilder(noun).reverse().toString()));
    }

    private NounCoordinates reverseNounCoordinates(NounCoordinates nounCoordinates) {
        return new NounCoordinates(nounCoordinates.nounEnd(), nounCoordinates.nounBegin());
    }

    public NounCoordinates doAHorizontalSearch(String noun) {
        for(int row = 0; row < input.length; row++) {
            for(int column = 0; column < input[0].length - noun.length() + 1; column++) {
                if(isNounContainedInThisRowFromThisColumn(noun, row, column))
                    return new NounCoordinates(new Coordinate(row, column), new Coordinate(row, column + noun.length() - 1));
            }
        }
        return new NounCoordinates(new Coordinate(-1, -1), new Coordinate(-1, -1));
    }

    private boolean isNounContainedInThisRowFromThisColumn(String noun, int row, int column) {
        int nounIndex = 0;
        for(int inputSubIndex = column; inputSubIndex < column + noun.length(); inputSubIndex++)
            if(input[row][inputSubIndex] != noun.charAt(nounIndex++)) return false;
        return true;
    }

    public NounCoordinates doAReverseHorizontalSearch(String noun) {
        return reverseNounCoordinates(doAHorizontalSearch(new StringBuilder(noun).reverse().toString()));
    }
}