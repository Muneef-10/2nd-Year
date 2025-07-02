import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MouseLambdaExample {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Mouse Listener Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new FlowLayout());

        JButton button = new JButton("Click Me");
        frame.add(button);

        // Using a lambda expression to handle mouse events
        button.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                System.out.println("Mouse Clicked");
            }

            @Override
            public void mousePressed(MouseEvent e) {
                System.out.println("Mouse Pressed");
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                System.out.println("Mouse Released");
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                System.out.println("Mouse Entered");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                System.out.println("Mouse Exited");
            }
        });

        frame.setVisible(true);
    }
}