/**
 * Created by nbr on 09/10/15.
 */
 class Bicycle {

    int cadence;
    int gear;
    int speed;

    public Bicycle(int startCadence, int startGear, int startSpeed)
    {
        cadence = startCadence;
        speed = startSpeed;
        gear = startGear;
    }

    public void setCadence(int newValue) {
        cadence = newValue;
    }

    public void setGear(int newValue) {
        gear = newValue;
    }

    public void applyBrake(int decrement) {
        speed -= decrement;
    }

    public void speedUp(int increment) {
        speed += increment;
    }

    protected int getSpeed() {
        return speed;
    }

}
