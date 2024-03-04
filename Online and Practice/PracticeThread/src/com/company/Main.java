package com.company;
import java.util.Random;

class ParallelMax implements Runnable {
    Thread t;
    private int[] demo = new int[200];
    private int in;
    private int max = Integer.MIN_VALUE;
    private int threadNumber;

    ParallelMax(int threadnum, int[] a, int index)
    {
        this.demo = a;
        this.in = index;
        this.threadNumber = threadnum;
        this.t = new Thread(this);
        this.t.start();
    }

    @Override
    public void run() {
        //System.out.println("Running thread");
        for (int i = in; i < in+200; i++)
        {
            if (demo[i] > max)
            {
                max = demo[i];
            }
        }
        System.out.println("Maximum in thread " + threadNumber + ": " + max);
    }

    public int getMax()
    {
        return max;
    }
    // your code here
}

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        int [] numbers = new int[1000];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt();
        }
        ParallelMax [] parallelMax = new ParallelMax[5];

        parallelMax[0] = new ParallelMax(1, numbers, 0);
        parallelMax[1] = new ParallelMax(2, numbers, 200);
        parallelMax[2] = new ParallelMax(3, numbers, 400);
        parallelMax[3] = new ParallelMax(4, numbers, 600);
        parallelMax[4] = new ParallelMax(5, numbers, 800);

        try {
            parallelMax[0].t.join();
            parallelMax[1].t.join();
            parallelMax[2].t.join();
            parallelMax[3].t.join();
            parallelMax[4].t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < 5; i++)
        {
            if (parallelMax[i].getMax() > max)
                max = parallelMax[i].getMax();
        }
        System.out.println("Maximum is " + max);
        // your code here
    }
}

