import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        new Main().execute();
    }

    private void execute() {
        CatchThemAllGame game = new CatchThemAllGame(readPlatforms());
        System.out.println(game.autoPlay());
    }

    private Platforms readPlatforms() {
        Platforms platforms = new Platforms();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        InputTransformer transformer = new InputTransformer();
        return platforms;
    }
}
