import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
        List<String> input = new LinkedList<String>();
        String line;
        while((line = bufferRead.readLine()) != null)
            input.add(line);
        Map<String, NounCoordinates> searchResults = new LinkedHashMap<String, NounCoordinates>();
        for(String nounToSearch : new InputTransformer(input).nounsToSearch())
            searchResults.put(nounToSearch, new NounFinder(new InputTransformer(input).transformInputIntoMatrix()).find(nounToSearch));
        System.out.print(new ResultView(searchResults).display());
    }
}
