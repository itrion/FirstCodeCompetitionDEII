import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class InputTransformerTest {

    @Test
    public void readingTheNumberOfPlatforms() {
        assertEquals(1, new InputTransformer().readNumberOfPlatforms("01"));
        assertEquals(2, new InputTransformer().readNumberOfPlatforms("02"));
        assertEquals(10, new InputTransformer().readNumberOfPlatforms("10"));
        assertEquals(50, new InputTransformer().readNumberOfPlatforms("50"));
    }

    @Test
    public void readingNextPlatform(){
        assertEquals(-3, new InputTransformer().readNextPlatform("-030502")[0]);
        assertEquals(5, new InputTransformer().readNextPlatform("-030502")[1]);
        assertEquals(2, new InputTransformer().readNextPlatform("-030502")[2]);
        assertEquals(Platforms.DIRECTION_DOWN, new InputTransformer().readNextPlatform("-030502")[3]);
        assertEquals(-12, new InputTransformer().readNextPlatform("-124000")[0]);
        assertEquals(40, new InputTransformer().readNextPlatform("-124000")[1]);
        assertEquals(0, new InputTransformer().readNextPlatform("-124000")[2]);
        assertEquals(Platforms.DIRECTION_DOWN, new InputTransformer().readNextPlatform("-124000")[3]);
    }
}
