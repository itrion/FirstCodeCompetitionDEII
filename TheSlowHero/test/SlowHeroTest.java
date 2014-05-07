import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class SlowHeroTest {
    @Test
    public void exampleTest() {
        InputReader reader = getMockReaderForExample();
        Platforms platforms = new Platforms();
        for(int i = 0; i < reader.readNumberOfPlatforms(); i++)
            platforms.add(reader.readNextPlatform());
        CatchThemAllGame game = new CatchThemAllGame(platforms);
        assertEquals(-1, game.autoPlay());
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
}
