public class Mammal extends Animal {
    private String bloodType = "Warm-Blooded!";

    public Mammal(String name, int age)
    {
        super(name, age);
    }

    public void printBloodType()
    {
        System.out.print(", " + bloodType);
    }
}
