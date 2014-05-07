import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class SlowHeroTest {
    @Test
    public void exampleTest() {
        InputReader reader = getMockReaderForExample();
        executeTestWithReaderAndExpectedTime(reader, -1);
    }

    @Test
    public void firstTestFromChallenge() {
        InputReader reader = getMockReaderForFirstTestFromChallenge();
        executeTestWithReaderAndExpectedTime(reader, -1);
    }

    @Test
    public void secondTestFromChallenge() {
        InputReader reader = getMockReaderForSecondTestFromChallenge();
        executeTestWithReaderAndExpectedTime(reader, 18);
    }

    private void executeTestWithReaderAndExpectedTime(InputReader reader, int expectedTime) {
        Platforms platforms = new Platforms();
        for(int i = 0; i < reader.readNumberOfPlatforms(); i++)
            platforms.add(reader.readNextPlatform());
        assertEquals(expectedTime, new CatchThemAllGame(platforms).autoPlay());
    }

    private InputReader getMockReaderForExample() {
        InputReader inputReader = mock(InputReader.class);
        when(inputReader.readNumberOfPlatforms()).
                thenReturn(3);
        when(inputReader.readNextPlatform()).
                thenReturn(
                        new int[]{-1, 2, 1},
                        new int[]{0, 3, 0},
                        new int[]{-2, 1, 0});
        return inputReader;
    }

    private InputReader getMockReaderForFirstTestFromChallenge() {
        InputReader inputReader = mock(InputReader.class);
        when(inputReader.readNumberOfPlatforms()).
                thenReturn(4);
        when(inputReader.readNextPlatform()).
                thenReturn(
                        new int[]{-1, 2, 1},
                        new int[]{0, 3, 0},
                        new int[]{4, 0, 0},
                        new int[]{-2, 1, 0});
        return inputReader;
    }

    private InputReader getMockReaderForSecondTestFromChallenge() {
        InputReader inputReader = mock(InputReader.class);
        when(inputReader.readNumberOfPlatforms()).
                thenReturn(2);
        when(inputReader.readNextPlatform()).
                thenReturn(
                        new int[]{-3, 0, 0},
                        new int[]{0, 3, 0});
        return inputReader;

    }
}
