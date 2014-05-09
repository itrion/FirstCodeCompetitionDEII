public class InputTransformer {

    public InputTransformer() {
    }

    public int readNumberOfPlatforms(String line) {
        return Integer.parseInt(line);
    }

    public int[] readNextPlatform(String line) {
        int i = 0;
        int platformIndex = 0;
        int[] nextPlatform = new int[4];
        while(i < line.length()) {
            if(nextNumberIsNegative(line, i)) {
                nextPlatform[platformIndex] = Integer.parseInt(line.substring(i, i + 3));
                i += 3;
            } else {
                nextPlatform[platformIndex] = Integer.parseInt(line.substring(i, i + 2));
                i += 2;
            }
            platformIndex++;
        }
        return nextPlatform;
    }

    private boolean nextNumberIsNegative(String line, int index) {
        return line.charAt(index) == '-';
    }
}
