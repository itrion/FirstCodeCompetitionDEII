import org.challenge.InputParser;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class InputParserTest {
    @Test
    public void parseAOneByOneMatrix(){
        String[] input = {"a"};
        InputParser inputParser = new InputParser(input);
        assertEquals('a', inputParser.transformInputIntoMatrix()[0][0]);
    }

    @Test
    public void parseATreeByTreeMatrix(){
        String[] input = {"aaa\nbbb\nccc"};
        InputParser inputParser = new InputParser(input);
        assertEquals('a', inputParser.transformInputIntoMatrix()[0][0]);
        assertEquals('b', inputParser.transformInputIntoMatrix()[1][0]);
        assertEquals('c', inputParser.transformInputIntoMatrix()[2][0]);
    }

    @Test
    public void thereisOneNoun(){
        String[] input = {"", "Mike"};
        InputParser inputParser = new InputParser(input);
        assertEquals(1, inputParser.extractNounsToSearch().length);
        assertEquals("Mike", inputParser.extractNounsToSearch()[0]);
    }
    @Test
    public void thereAreTwoNouns(){
        String[] input = {"", "Mike", "Sully"};
        InputParser inputParser = new InputParser(input);
        assertEquals(2, inputParser.extractNounsToSearch().length);
        assertEquals("Mike", inputParser.extractNounsToSearch()[0]);
        assertEquals("Sully", inputParser.extractNounsToSearch()[1]);
    }
    @Test
    public void thereAreThreeNouns(){
        String[] input = {"", "Mike", "Sully", "Randall"};
        InputParser inputParser = new InputParser(input);
        assertEquals(3, inputParser.extractNounsToSearch().length);
        assertEquals("Mike", inputParser.extractNounsToSearch()[0]);
        assertEquals("Sully", inputParser.extractNounsToSearch()[1]);
        assertEquals("Randall", inputParser.extractNounsToSearch()[2]);
    }
}
