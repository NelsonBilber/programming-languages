/**
 * Created by nbr on 09/10/15.
 */
public class Main {
    public static void main(String[] args)
    {
        Bicycle b = new Bicycle(10,11,12);
        System.out.println(b.getSpeed());

        MountainBike mb = new MountainBike(13,14,14,15);
        System.out.println(mb.getSpeed());

    }
}
