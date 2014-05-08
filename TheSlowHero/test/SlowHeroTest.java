import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class SlowHeroTest {
    @Test
    public void exampleTest() {
        InputTransformer reader = getMockReaderForExample();
        executeTestWithReaderAndExpectedTime(reader, -1);
    }

    @Test
    public void firstTestFromChallenge() {
        InputTransformer reader = getMockReaderForFirstTestFromChallenge();
        executeTestWithReaderAndExpectedTime(reader, -1);
    }

    @Test
    public void secondTestFromChallenge() {
        InputTransformer reader = getMockReaderForSecondTestFromChallenge();
        executeTestWithReaderAndExpectedTime(reader, 18);
    }

    private void executeTestWithReaderAndExpectedTime(InputTransformer reader, int expectedTime) {
        Platforms platforms = new Platforms();
        for(int i = 0; i < reader.readNumberOfPlatforms(""); i++)
            platforms.add(reader.readNextPlatform(""));
        assertEquals(expectedTime, new CatchThemAllGame(platforms).autoPlay());
    }

    private InputTransformer getMockReaderForExample() {
        InputTransformer mockInputReader = mock(InputTransformer.class);
        when(mockInputReader.readNumberOfPlatforms("")).
                thenReturn(3);
        when(mockInputReader.readNextPlatform("")).
                thenReturn(
                        new int[]{-1, 2, 1, Platforms.DIRECTION_DOWN},
                        new int[]{0, 3, 0, Platforms.DIRECTION_DOWN},
                        new int[]{-2, 1, 0, Platforms.DIRECTION_DOWN});
        return mockInputReader;
    }

    private InputTransformer getMockReaderForFirstTestFromChallenge() {
        InputTransformer mockInputReader = mock(InputTransformer.class);
        when(mockInputReader.readNumberOfPlatforms("")).
                thenReturn(4);
        when(mockInputReader.readNextPlatform("")).
                thenReturn(
                        new int[]{-1, 2, 1, Platforms.DIRECTION_DOWN},
                        new int[]{0, 3, 0, Platforms.DIRECTION_DOWN},
                        new int[]{4, 0, 0, Platforms.DIRECTION_DOWN},
                        new int[]{-2, 1, 0, Platforms.DIRECTION_DOWN});
        return mockInputReader;
    }

    private InputTransformer getMockReaderForSecondTestFromChallenge() {
        InputTransformer mockInputReader = mock(InputTransformer.class);
        when(mockInputReader.readNumberOfPlatforms("")).
                thenReturn(2);
        when(mockInputReader.readNextPlatform("")).
                thenReturn(
                        new int[]{-3, 0, 0, Platforms.DIRECTION_DOWN},
                        new int[]{0, 3, 0, Platforms.DIRECTION_DOWN});
        return mockInputReader;

    }
}
