import javax.swing.*;
public class GUI3 extends JFrame
{
    GUI3()
    {
        setTitle("Hello world Swings");
        setSize(300,200);

        JLabel label = new JLabel("Hello, Swing GUI!", JLabel.CENTER);
        
        JButton button = new JButton("Click me");
        button.setBounds(100,100,120,40);

        add(button);
        add(label);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }
    public static void main(String[] args) {
        new GUI3();
    }   
}