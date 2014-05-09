import java.util.LinkedList;
import java.util.List;

public class Platforms {
    private static final int MIN_HEIGHT_POSITION = 0;
    private static final int MAX_HEIGHT_POSITION = 1;
    private static final int HEIGHT_POSITION = 2;
    private static final int DIRECTION_POSITION = 3;
    public static final int DIRECTION_DOWN = 0;
    public static final int DIRECTION_UP = 1;
    public static final int PLATFORM_LENGTH = 4;

    private final List<int[]> platforms;

    public Platforms() {
        this.platforms = new LinkedList<>();
    }

    public Platforms add(int[] platform) {
        platforms.add(platform);
        return this;
    }

    public void move() {
        for(int[] platform : platforms) {
            platform[HEIGHT_POSITION] += calculateNextHeight(platform);
        }
    }

    public int getHeightOfPlatform(int platformNumber) {
        return platforms.get(platformNumber)[HEIGHT_POSITION];
    }

    private int calculateNextHeight(int[] platform) {
        if(platform[HEIGHT_POSITION] == platform[MAX_HEIGHT_POSITION]) platform[DIRECTION_POSITION] = DIRECTION_DOWN;
        else if(platform[HEIGHT_POSITION] == platform[MIN_HEIGHT_POSITION]) platform[DIRECTION_POSITION] = DIRECTION_UP;
        return (platform[DIRECTION_POSITION] == DIRECTION_DOWN) ? -1 : 1;
    }

    public int totalDistance() {
        return platforms.size() * PLATFORM_LENGTH;
    }

    public int numberOfPlatforms() {
        return platforms.size();
    }
}
