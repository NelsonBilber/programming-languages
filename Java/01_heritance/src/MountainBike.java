/**
 * Created by nbr on 09/10/15.
 */
public class MountainBike extends Bicycle {

    public int seatheight;

    public MountainBike(int startHeight, int startCadence,
                        int startSpeed, int startGear)
    {
        super(startCadence,startGear, startSpeed);
        seatHeight(startHeight);
    }

    public void seatHeight(int newValue)
    {
            seatheight = newValue;
    }
}
