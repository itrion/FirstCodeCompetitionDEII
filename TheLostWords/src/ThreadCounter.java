public class ThreadCounter {
    private int remainingCounters;

    public ThreadCounter(int numberOfThreadToCount) {
        this.remainingCounters = numberOfThreadToCount;
    }

    public synchronized int remainingCounters() {
        return remainingCounters;
    }

    public synchronized void notifyFinish() {
        remainingCounters--;
    }
}
