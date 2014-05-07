import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class SlowHeroTest {
    @Test
    public void exampleTest() {
        Platforms platforms = new Platforms();
        platforms.add(new Platform(-1, 2, 1));
        platforms.add(new Platform(0, 3, 0));
        platforms.add(new Platform(-2, 1, 0));
        CatchThemAllGame game = new CatchThemAllGame(platforms);
        int timeOfCrossing = game.play();
        assertEquals(-1, timeOfCrossing);
    }

    @Test
    public void firstTestFromChallenge(){
        assertTrue(false);
    }

    @Test
    public void secondTestFromChallenge(){
        assertTrue(false);
    }
}
