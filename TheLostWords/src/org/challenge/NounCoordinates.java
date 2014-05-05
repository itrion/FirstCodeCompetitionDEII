package org.challenge;

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
}
