public class EasternBrownSnake extends Reptile implements Venomous {
    public EasternBrownSnake(String steph, int i) {
        super(steph, i);
    }

    @Override
    public boolean isLethalToAdultHumans() {
        return true;
    }
}
