package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.io.Serializable;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Controller {
    @FXML private TextField UserName;
    @FXML private TextField PassWord;
    @FXML private Label NotifyLabel;
    @FXML private TextField viewerLogin;
    @FXML private Button ViewButton;


    public void Manbuttonpushed (ActionEvent event) throws IOException, ClassNotFoundException {
        Client.getNetworkUtil().write("Manufacture check");
        Client.getNetworkUtil().write(UserName.getText());
        Client.getNetworkUtil().write(PassWord.getText());
        String req = Client.login();

        if (req.equalsIgnoreCase("Found"))
        {
            Parent manufactureParent = FXMLLoader.load(getClass().getResource("Manufacturer.fxml"));
            Scene manufactureView = new Scene(manufactureParent);
            Stage window = (Stage) ((Node)event.getSource()).getScene().getWindow();

            window.setScene(manufactureView);
                //System.out.println("Setting man");
            window.show();
        }
        else if (req.equalsIgnoreCase("Not found"))
        {
            NotifyLabel.setText("Manufacturer not found");
        }

    }

    public void Viewbuttonpushed (ActionEvent event) throws IOException {
        String viewerId = viewerLogin.getText();
        Client.getViewerInfo().add(viewerId);

        Parent viewerParent = FXMLLoader.load(getClass().getResource("Viewer.fxml"));
        Scene viewerView = new Scene(viewerParent);
        Stage window = (Stage) ((Node)event.getSource()).getScene().getWindow();

        window.setScene(viewerView);
        window.show();
    }
}
