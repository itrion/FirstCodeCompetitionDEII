package org.challenge;

public class Coordinate {
    private int x;
    private int y;

    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int hashCode() {
        return ("" + x + ", " + y).hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Coordinate)) return false;
        Coordinate otherCoordinate = (Coordinate) obj;
        return (x == otherCoordinate.x) && (y == otherCoordinate.y);
    }

    @Override
    public String toString() {
        return "{x:" + x + ", y:" + y + '}';
    }
}
