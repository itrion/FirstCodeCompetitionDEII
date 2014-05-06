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
        String[] nounsToSearch = new InputTransformer(input).nounsToSearch();
        for(String noun : nounsToSearch)
            searchResults.put(noun, null);
        ThreadCounter finishCounter = new ThreadCounter(nounsToSearch.length);
        for(String nounToSearch : nounsToSearch)
            new NounFinder(new InputTransformer(input).transformInputIntoMatrix()).storeResultIn(searchResults).startSearch(nounToSearch, finishCounter);
        while(finishCounter.remainingCounters() < 0) {
        }
        System.out.print(new ResultView(searchResults).display());

    }
}
