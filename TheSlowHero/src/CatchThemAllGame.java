import java.util.LinkedHashMap;
import java.util.Map;

public class CatchThemAllGame {
    public static final int HERO_SPEED = 2;
    private static final int MAX_ITERATIONS = 100;
    private final Platforms platforms;
    private final Map<Integer, Integer> platformsIndexes;
    private int distanceCoveredByHero;
    private int totalDistance;
    private int iterations;

    public CatchThemAllGame(Platforms platforms) {
        this.platforms = platforms;
        this.distanceCoveredByHero = 0;
        this.totalDistance = platforms.totalDistance() + 4;
        this.iterations = 0;
        this.platformsIndexes = fillPlatformIndexes(platforms);
    }

    private Map<Integer, Integer> fillPlatformIndexes(Platforms platforms) {
        Map<Integer, Integer> indexes = new LinkedHashMap<>();
        int limit = 0;
        for(int i = 0; i < platforms.numberOfPlatforms(); i++) {
            indexes.put((limit += 2), i);
            indexes.put((limit += 2), i);
        }
        return indexes;
    }

    public int autoPlay() {
        while(hasTimeToPlay()) {
            if(remainingDistance() == 0) return iterations - 1;
            iterate();
        }
        return -1;
    }

    public void iterate() {
        iterations++;
        if(canMoveHero()) moveHero();
        platforms.move();
    }

    private boolean canMoveHero() {
        if(isFirstMovement()) return platforms.getHeightOfPlatform(0) == 0;
        if(isLastMovement()) return platforms.getHeightOfPlatform(platforms.numberOfPlatforms() - 1) == 0;
        return arePlatformAligned();
    }

    private boolean isFirstMovement() {
        return distanceCoveredByHero == 0;
    }

    private boolean isLastMovement() {
        return distanceCoveredByHero >= platforms.totalDistance();
    }

    private boolean arePlatformAligned() {
        return (platforms.getHeightOfPlatform(platformsIndexes.get(distanceCoveredByHero))
                == platforms.getHeightOfPlatform(platformsIndexes.get(distanceCoveredByHero + HERO_SPEED)));
    }

    private void moveHero() {
        distanceCoveredByHero += HERO_SPEED;
    }

    private boolean hasTimeToPlay() {
        return (iterations < MAX_ITERATIONS);
    }

    public int distanceCoveredByHero() {
        return distanceCoveredByHero;
    }

    public int remainingDistance() {
        return totalDistance - distanceCoveredByHero;
    }
}
