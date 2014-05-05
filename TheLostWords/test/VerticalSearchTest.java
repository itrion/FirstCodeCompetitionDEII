import org.challenge.Coordinate;
import org.challenge.NounFinder;
import org.junit.Test;
import static org.junit.Assert.*;


public class VerticalSearchTest {
    @Test
    public void testVerticalSearch(){
        String input = "a\nb\nc\nd\na\na\nb";
        String word = "aa";
        NounFinder nounFinder = new NounFinder();
        assertEquals(new Coordinate(0, 4), nounFinder.doAVerticalSearch(word, input).begin());
        assertEquals(new Coordinate(0, 5), nounFinder.doAVerticalSearch(word, input).end());
    }
}
