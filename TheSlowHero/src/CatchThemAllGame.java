public class CatchThemAllGame {
    public static final int HERO_SPEED = 2;
    private static final int MAX_ITERATIONS = 100;
    private final Platforms platforms;
    private int distanceCoveredByHero;
    private int totalDistance;
    private int iterations;

    public CatchThemAllGame(Platforms platforms) {
        this.platforms = platforms;
        this.distanceCoveredByHero = 0;
        this.totalDistance = platforms.totalDistance() + 4;
        this.iterations = 0;
    }

    public int autoPlay() {
        while(hasTimeToPlay()) {
            iterate();
            if(remainingDistance() == 0) return iterations;
        }
        return -1;
    }

    public void iterate() {
        iterations++;
        if(canMoveHero()) moveHero();
        platforms.move();
    }

    private boolean canMoveHero() {
        int heroPlatform = distanceCoveredByHero % 2;
        return heroPlatform < 1 ||
                platforms.getHeightOfPlatform(heroPlatform) == platforms.getHeightOfPlatform(heroPlatform + 1);
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
