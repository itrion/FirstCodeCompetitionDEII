import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        new Main().execute();
    }

    private void execute() throws IOException {
        Platforms platforms = readPlatforms(new BufferedReader(new InputStreamReader(System.in)));
        System.out.println(new CatchThemAllGame(platforms).autoPlay());
    }

    private Platforms readPlatforms(BufferedReader reader) throws IOException {
        Platforms platforms = new Platforms();
        InputTransformer inputTransformer = new InputTransformer();
        int numberOfPlatforms = inputTransformer.readNumberOfPlatforms(reader.readLine());
        for(int i = 0; i < numberOfPlatforms; i++){
            String line = reader.readLine();
            platforms.add(inputTransformer.readNextPlatform(line));
        }
        return platforms;
    }
}
