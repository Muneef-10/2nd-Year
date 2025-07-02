import javax.swing.*;
public class GUI2 extends JFrame
{
    GUI2()
    {
        setSize(300,200);

        JLabel label = new JLabel("Hello, Swing GUI!", JLabel.CENTER);
        add(label);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    public static void main(String[] args) {
        new GUI2();
    }   
}