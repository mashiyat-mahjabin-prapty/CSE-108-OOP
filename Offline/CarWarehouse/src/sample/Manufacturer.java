package sample;

import java.util.ArrayList;
import java.util.List;

public class Manufacturer {
    private String UserName;
    private String Password;
    private static List<Manufacturer> manufacturerList = new ArrayList<>();
    public static final String FILE_NAME_MAN = "manufacturer.txt";

    public static List<Manufacturer> getManufacturerList() {
        return manufacturerList;
    }

    public static void setManufacturerList(List<Manufacturer> manufacturer) {
        manufacturerList = manufacturer;
    }

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String userName) {
        UserName = userName;
    }

    public String getPassword() {
        return Password;
    }

    public void setPassword(String password) {
        Password = password;
    }

    public void login(String user, String pass)
    {

    }
}
