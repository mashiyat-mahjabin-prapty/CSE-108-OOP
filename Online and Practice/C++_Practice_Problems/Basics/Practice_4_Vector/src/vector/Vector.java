package vector;

public class Vector {
    private int[] vector;
    private int size;
    private int maximumCapacity;
    private int isUnboundedVector;

    public Vector(){
        this.size = 2;
        this.vector[] = new int[this.size];
        this.vector[0] = 0;
        this.vector[1] = 0;
        this.isUnboundedVector = 1;
    }
    public Vector(int capacity){
        this.maximumCapacity = capacity;
        this.vector[] = new int[this.maximumCapacity];
        this.isUnboundedVector = 0;
    }

    public void add(int value){
        if(this.isUnboundedVector){
            this.size = this.size+1;
            this.vector[] = new int[this.size];

        }
    }

    public static void main(String[] args){

    }
}
