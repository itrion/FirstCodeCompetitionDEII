import org.junit.Before;
import org.junit.Test;

import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.assertEquals;

public class ConcurrencyApi {
    private List<String> input;
    private NounFinder finder;

    @Before
    public void setUp() {
        input = new LinkedList<String>();
        input.add("\"ELVISTEKASDFHJKL\\nSOLEODILODFHJKLK\\nELSAPATOASDFHJKL\"");
        input.add("\"ELVIS\"");
        input.add("\"SOL\"");
        input.add("\"DOLIDO\"");
        finder = new NounFinder(new InputTransformer(input).transformInputIntoMatrix());
    }

    @Test
    public void Foo() {
        Map<String, NounCoordinates> store = new LinkedHashMap<String, NounCoordinates>();
        int numberOfThreadToCount = 1;
        ThreadCounter threadFinishedCounter = new ThreadCounter(numberOfThreadToCount);
        store.put("ELVIS", null);
        finder.storeResultIn(store).startSearch("ELVIS", threadFinishedCounter);
        while(threadFinishedCounter.remainingCounters() > 0){}
        assertEquals(new NounCoordinates(new Coordinate(0, 0), new Coordinate(0, 4)), store.get("ELVIS"));
    }
}
