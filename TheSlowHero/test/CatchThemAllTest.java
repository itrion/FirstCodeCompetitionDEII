import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class CatchThemAllTest {

    @Test
    public void heroMovesInEveryGameIteration() {
        Platforms platforms = new Platforms();
        platforms.add(new int[]{0, 0, 0, 0});
        platforms.add(new int[]{0, 0, 0, 0});
        CatchThemAllGame game = new CatchThemAllGame(platforms);
        game.iterate();
        game.iterate();
        assertEquals(4, game.distanceCoveredByHero());
        game.iterate();
        assertEquals(6, game.distanceCoveredByHero());
    }

    @Test
    public void remainingDistance() {
        assertEquals(4, new CatchThemAllGame(new Platforms()).remainingDistance());
        assertEquals(8, new CatchThemAllGame(new Platforms().add(new int[]{0, 0, 0})).remainingDistance());
        assertEquals(12, new CatchThemAllGame(new Platforms().add(new int[]{0, 0, 0}).add(new int[]{0, 0, 0})).remainingDistance());
        assertEquals(16, new CatchThemAllGame(new Platforms().add(new int[]{0, 0, 0}).add(new int[]{0, 0, 0}).add(new int[]{0, 0, 0})).remainingDistance());
    }

}
