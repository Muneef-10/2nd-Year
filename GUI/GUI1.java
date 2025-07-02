// package GUI;
import javax.swing.*;
public class GUI1
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Hello World Swings");
        frame.setSize(600,400);

        JLabel label = new JLabel("Muneef Khan", JLabel.CENTER);
        frame.add(label);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }   
}