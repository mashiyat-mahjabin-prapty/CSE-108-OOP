package com.company;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class FileOp {
    public static final String FILE_NAME = "cars.txt";
    public static final String MAP_NAME = "manufacturer.txt";

    public static void fileRead(List list) {
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME)))
        {
            while(true)
            {
                String line;
                Car temp = new Car();
                line = br.readLine();
                if (line == null) break;
                temp.setCar(line);
                list.add(temp);
                //temp.printCar();
            }
            br.close();
        } catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static void fileWrite(List list)
    {
        try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(FILE_NAME)))
        {
            for(int i = 0; i < list.size(); i++)
            {
                Car car;
                car = (Car) list.get(i);
                String line;
                line = car.getRegistrationNo() + "," + car.getYearMade() + "," + car.getColour1() +
                        "," + car.getColour2() + "," + car.getColour3() +
                        "," + car.getCarMake() + "," + car.getCarModel() + "," + car.getPrice() + "\n";
                bufferedWriter.write(line);
            }
            bufferedWriter.close();
        } catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static void mapRead(Map map)
    {
        try (BufferedReader br = new BufferedReader(new FileReader(MAP_NAME)))
        {
            while(true)
            {
                String line;
                line = br.readLine();
                System.out.println(line);
                if (line == null) break;
                String[] str = line.split(",");
                map.put(str[0], str[1]);
            }
            br.close();
        } catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}
