import java.util.Map;

public class ResultView {
    private Map<String, NounCoordinates> input;

    public ResultView(Map<String, NounCoordinates> input) {
        this.input = input;
    }

    public String display() {
        StringBuilder builder = new StringBuilder();
        for(String noun : input.keySet()) {
            builder.append(noun).append(input.get(noun).toString()).append("\n");
        }
        return builder.toString();
    }
}
