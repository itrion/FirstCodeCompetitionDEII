package org.challenge;

public class NounFinder {
    private char[][] input;

    public NounFinder(char[][] input) {
        this.input = input;
    }

    public NounCoordinates doAVerticalSearch(String noun) {
        for(int column = 0; column < input.length; column++)
            for(int row = 0; row < input.length; row++)
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
}
