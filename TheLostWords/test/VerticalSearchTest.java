import org.challenge.Coordinate;
import org.challenge.NounFinder;
import org.junit.Test;

import static org.junit.Assert.assertEquals;


public class VerticalSearchTest {
    @Test
    public void theNounIsInTheFirstColumn() {
        char[][] input = {
                {'a'},
                {'b'},
                {'c'},
                {'d'},
                {'a'},
                {'a'},
                {'b'}};
        String noun = "aa";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(new Coordinate(4, 0), nounFinder.doAVerticalSearch(noun).nounBegin());
        assertEquals(new Coordinate(5, 0), nounFinder.doAVerticalSearch(noun).nounEnd());
    }

    @Test
    public void theNounIsInTheSecondColumn() {
        char[][] input = {
                {'x', 'a', 'x'},
                {'x', 'b', 'x'},
                {'x', 'c', 'x'},
                {'x', 'd', 'x'},
                {'x', 'a', 'x'},
                {'x', 'a', 'x'},
                {'x', 'b', 'x'}};
        String noun = "aa";
        NounFinder nounFinder = new NounFinder(input);
        assertEquals(new Coordinate(4, 1), nounFinder.doAVerticalSearch(noun).nounBegin());
        assertEquals(new Coordinate(5, 1), nounFinder.doAVerticalSearch(noun).nounEnd());
    }

}
