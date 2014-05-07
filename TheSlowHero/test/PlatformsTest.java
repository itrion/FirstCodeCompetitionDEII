import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class PlatformsTest {
    @Test
    public void platformsAdvanceOneMeterPerSecond(){
        Platforms platforms = new Platforms().add(new int[]{-2, 2, 2, Platforms.DIRECTION_DOWN}).add(new int[]{-1, 1, 1, Platforms.DIRECTION_DOWN});
        platforms.move();
        platforms.move();
        platforms.move();
        platforms.move();
        assertEquals(-2, platforms.getHeightOfPlatform(0));
        assertEquals(1, platforms.getHeightOfPlatform(1));
    }

    @Test
    public void totalDistance(){
        assertEquals(4, new Platforms().add(new int[]{0, 0, 0, 0}).totalDistance());
        assertEquals(8, new Platforms().add(new int[]{0, 0, 0, 0}).add(new int[]{0, 0, 0, 0}).totalDistance());
        assertEquals(12, new Platforms().add(new int[]{0, 0, 0, 0}).add(new int[]{0, 0, 0, 0}).add(new int[]{0, 0, 0, 0}).totalDistance());
    }
}
