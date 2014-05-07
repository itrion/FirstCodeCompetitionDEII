public class NounFinder{
    private char[][] input;
    private NounCoordinates lastFoundCoordinate;

    public NounFinder(char[][] input) {
        this.input = input;
    }

    public NounCoordinates find(String noun) {
        if (isInRows(noun)) return lastFoundCoordinate;
        else if(isInColumns(noun)) return lastFoundCoordinate;
        return lastFoundPosition();
    }

    public boolean isInRows(String noun) {
        doAHorizontalSearch(noun);
        return lastFoundCoordinate != null;
    }

    public boolean isInColumns(String noun) {
        doAVerticalSearch(noun);
        return lastFoundCoordinate != null;
    }

    public void doAVerticalSearch(String noun) {
        for(int column = 0; column < input[0].length; column++)
            for(int row = 0; row < input.length - noun.length() + 1; row++) {
                if(isNounContainedInThisColumnFromThisRow(noun, column, row)) {
                    lastFoundCoordinate = new NounCoordinates(new Coordinate(row, column), new Coordinate(row + noun.length() - 1, column));
                    return;
                } else if(isNounContainedInThisColumnFromThisRow(reverseNoun(noun), column, row)) {
                    lastFoundCoordinate = reverseNounCoordinates(new NounCoordinates(new Coordinate(row, column), new Coordinate(row + noun.length() - 1, column)));
                    return;
                }
            }
        lastFoundCoordinate = null;
    }

    private boolean isNounContainedInThisColumnFromThisRow(String noun, int column, int row) {
        int nounIndex = 0;
        for(int inputSubIndex = row; inputSubIndex < row + noun.length(); inputSubIndex++)
            if(input[inputSubIndex][column] != noun.charAt(nounIndex++)) return false;
        return true;
    }

    public void doAHorizontalSearch(String noun) {
        for(int row = 0; row < input.length; row++) {
            for(int column = 0; column < input[0].length - noun.length() + 1; column++) {
                if(isNounContainedInThisRowFromThisColumn(noun, row, column)) {
                    lastFoundCoordinate = new NounCoordinates(new Coordinate(row, column), new Coordinate(row, column + noun.length() - 1));
                    return;
                } else if(isNounContainedInThisRowFromThisColumn(reverseNoun(noun), row, column)) {
                    lastFoundCoordinate = reverseNounCoordinates(new NounCoordinates(new Coordinate(row, column), new Coordinate(row, column + noun.length() - 1)));
                    return;
                }
            }
        }
        lastFoundCoordinate = null;
    }

    private boolean isNounContainedInThisRowFromThisColumn(String noun, int row, int column) {
        int nounIndex = 0;
        for(int inputSubIndex = column; inputSubIndex < column + noun.length(); inputSubIndex++)
            if(input[row][inputSubIndex] != noun.charAt(nounIndex++)) return false;
        return true;
    }

    public String reverseNoun(String noun) {
        return new StringBuilder(noun).reverse().toString();
    }

    private NounCoordinates reverseNounCoordinates(NounCoordinates nounCoordinates) {
        return new NounCoordinates(nounCoordinates.nounEnd(), nounCoordinates.nounBegin());
    }

    public NounCoordinates lastFoundPosition() {
        return (lastFoundCoordinate == null) ? new NounCoordinates(new Coordinate(-1, -1), new Coordinate(-1, -1)) : lastFoundCoordinate;
    }
}