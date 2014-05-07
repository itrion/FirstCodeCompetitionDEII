import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class HorizontalSearchTest {
    @Test
    public void theNounIsInTheFirstRow() {
        char[][] input = {
                {'a', 'b', 'c', 'd', 'a', 'a', 'b'},
                {'x', 'x', 'x', 'x', 'x', 'x', 'x'}};
        String noun = "aab";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(true, nounFinder.isInRows(noun));
        assertEquals(new Coordinate(0, 4), nounFinder.lastFoundPosition().nounBegin());
        assertEquals(new Coordinate(0, 6), nounFinder.lastFoundPosition().nounEnd());
    }

    @Test
    public void theNounIsInTheSecondRow() {
        char[][] input = {
                {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
                {'a', 'b', 'c', 'a', 'a', 'b', 'b'}};
        String noun = "aab";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(true, nounFinder.isInRows(noun));
        assertEquals(new Coordinate(1, 3), nounFinder.lastFoundPosition().nounBegin());
        assertEquals(new Coordinate(1, 5), nounFinder.lastFoundPosition().nounEnd());
    }

    @Test
    public void theNounIsReversedInTheFirsRow() {
        char[][] input = {
                {'a', 'b', 'c', 'a', 'a', 'b', 'b'},
                {'x', 'x', 'x', 'x', 'x', 'x', 'x'}};
        String noun = "acb";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(true, nounFinder.isInRows(noun));
        assertEquals(new Coordinate(0, 3), nounFinder.lastFoundPosition().nounBegin());
        assertEquals(new Coordinate(0, 1), nounFinder.lastFoundPosition().nounEnd());
    }

    @Test
    public void theNounIsReversedInTheSecondRow() {
        char[][] input = {
                {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
                {'a', 'b', 'c', 'a', 'a', 'b', 'b'}};
        String noun = "baacba";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(true, nounFinder.isInRows(noun));
        assertEquals(new Coordinate(1, 5), nounFinder.lastFoundPosition().nounBegin());
        assertEquals(new Coordinate(1, 0), nounFinder.lastFoundPosition().nounEnd());
    }

    @Test
    public void theNounIsNotCompleteInTheRow() {
        char[][] input = {{'a', 'b', 'c', 'd'}};
        String noun = "cde";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(false, nounFinder.isInRows(noun));
        assertEquals(new Coordinate(-1, -1), nounFinder.lastFoundPosition().nounBegin());
        assertEquals(new Coordinate(-1, -1), nounFinder.lastFoundPosition().nounEnd());
    }
}
