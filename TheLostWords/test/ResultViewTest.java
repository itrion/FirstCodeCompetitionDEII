import org.junit.Test;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import static org.junit.Assert.assertEquals;

public class ResultViewTest {
    @Test
    public void resultIsInRequiredFormat() {
        Map<String, NounCoordinates> input = new ConcurrentHashMap<String, NounCoordinates>();
        input.put("ELVIS", new NounCoordinates(new Coordinate(0, 1), new Coordinate(0, 3)));
        ResultView resultView = new ResultView(input);
        assertEquals("ELVIS((0,1),(0,3))\n", resultView.display());
    }
}
