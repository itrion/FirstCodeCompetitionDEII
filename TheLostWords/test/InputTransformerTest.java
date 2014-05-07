import org.junit.Test;

import java.util.LinkedList;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class InputTransformerTest {
    @Test
    public void parseAOneByOneMatrix(){
        List<String> input = new LinkedList<String>();
        input.add("a");
        InputTransformer inputTransformer = new InputTransformer(input);
        assertEquals('a', inputTransformer.transformInputIntoMatrix()[0][0]);
    }

    @Test
    public void parseATreeByTreeMatrix(){
        List<String> input = new LinkedList<String>();
        input.add("\"aaa\\nbbb\\nccc\"");
        InputTransformer inputTransformer = new InputTransformer(input);
        assertEquals('a', inputTransformer.transformInputIntoMatrix()[0][0]);
        assertEquals('b', inputTransformer.transformInputIntoMatrix()[1][0]);
        assertEquals('c', inputTransformer.transformInputIntoMatrix()[2][0]);
    }

    @Test
    public void thereisOneNoun(){
        List<String> input = new LinkedList<String>();
        input.add("");
        input.add("Mike");
        InputTransformer inputTransformer = new InputTransformer(input);
        assertEquals(1, inputTransformer.nounsToSearch().length);
        assertEquals("Mike", inputTransformer.nounsToSearch()[0]);
    }
    @Test
    public void thereAreTwoNouns(){
        List<String> input = new LinkedList<String>();
        input.add("");
        input.add("Mike");
        input.add("Sully");
        InputTransformer inputTransformer = new InputTransformer(input);
        assertEquals(2, inputTransformer.nounsToSearch().length);
        assertEquals("Mike", inputTransformer.nounsToSearch()[0]);
        assertEquals("Sully", inputTransformer.nounsToSearch()[1]);
    }
    @Test
    public void thereAreThreeNouns(){
        List<String> input = new LinkedList<String>();
        input.add("");
        input.add("Mike");
        input.add("Sully");
        input.add("Randall");
        InputTransformer inputTransformer = new InputTransformer(input);
        assertEquals(3, inputTransformer.nounsToSearch().length);
        assertEquals("Mike", inputTransformer.nounsToSearch()[0]);
        assertEquals("Sully", inputTransformer.nounsToSearch()[1]);
        assertEquals("Randall", inputTransformer.nounsToSearch()[2]);
    }
}
