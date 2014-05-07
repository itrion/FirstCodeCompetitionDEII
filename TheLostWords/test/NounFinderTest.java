import org.junit.Before;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class NounFinderTest {

    @Before
    public void setUp() {
        input = new LinkedList<String>();
        input.add("\"ELVISTEKASDFHJKL\\nSOLEODILODFHJKLK\\nELSAPATOASDFHJKL\"");
        input.add("\"ELVIS\"");
        input.add("\"SOL\"");
        input.add("\"DOLIDO\"");
        nounFinder = new NounFinder(new InputTransformer(input).transformInputIntoMatrix());
    }
    public List<String> input;

    private NounFinder nounFinder;

    @Test
    public void findElvis() {
        assertEquals(new NounCoordinates(new Coordinate(0, 0), new Coordinate(0, 4)), nounFinder.find("ELVIS"));
    }

    @Test
    public void findSol() {
        assertEquals(new NounCoordinates(new Coordinate(1, 0), new Coordinate(1, 2)), nounFinder.find("SOL"));
    }

    @Test
    public void findDolido() {
        assertEquals(new NounCoordinates(new Coordinate(1, 9), new Coordinate(1, 4)), nounFinder.find("DOLIDO"));
    }
}
