package sample;

import javafx.collections.ObservableList;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.List;
import java.util.Map;

public class FileOp {



    public static void fileRead(List list, String fileName) {
        {
            try (BufferedReader br = new BufferedReader(new FileReader(fileName)))
            {
                while(true)
                {
                    String line;
                    if (fileName == "cars.txt")
                    {
                        Car temp = new Car();
                        line = br.readLine();
                        if (line == null) break;
                        temp.setCar(line);
                        list.add(temp);
                    }
                    if (fileName == "manufacturer.txt")
                    {
                        Manufacturer temp = new Manufacturer();
                        line = br.readLine();
                        if (line == null) break;
                        String[] str = line.split(",");
                        temp.setUserName(str[0]);
                        temp.setPassword(str[1]);
                        list.add(temp);
                    }
                    //temp.printCar();
                }
                br.close();
            } catch(Exception e)
            {
                e.printStackTrace();
            }
        }
    }

    public static void fileWrite(ObservableList<Car> list, String fileName)
    {
        try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(fileName)))
        {
            System.out.println(list.size());
            for(int i = 0; i < list.size(); i++)
            {
                System.out.println(i);
                Car car = list.get(i);
                car.printCar();
                String line;
                line = car.getRegistrationNo() + "," + car.getYearMade() + "," + car.getColours() +
                        "," + car.getCarMake() + "," + car.getCarModel() + "," + car.getPrice() + "\n";
                bufferedWriter.write(line);
            }
            bufferedWriter.close();
        } catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}
