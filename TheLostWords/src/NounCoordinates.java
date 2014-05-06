public class NounCoordinates {

    private Coordinate nounBegin;
    private Coordinate nounEnd;

    public NounCoordinates(Coordinate nounBegin, Coordinate nounEnd) {
        this.nounBegin = nounBegin;
        this.nounEnd = nounEnd;
    }

    public Coordinate nounBegin() {
        return nounBegin;
    }

    public Coordinate nounEnd() {
        return nounEnd;
    }

    @Override
    public boolean equals(Object otherObject) {
        if(this == otherObject) return true;
        if(!(otherObject instanceof NounCoordinates)) return false;
        NounCoordinates that = (NounCoordinates) otherObject;
        if(nounBegin != null ? !nounBegin.equals(that.nounBegin) : that.nounBegin != null) return false;
        return !(nounEnd != null ? !nounEnd.equals(that.nounEnd) : that.nounEnd != null);

    }

    @Override
    public int hashCode() {
        int result = nounBegin != null ? nounBegin.hashCode() : 0;
        result = 31 * result + (nounEnd != null ? nounEnd.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        return String.format("(%s,%s)", nounBegin, nounEnd);
    }
}
