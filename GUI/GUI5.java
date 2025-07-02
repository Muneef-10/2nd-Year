import javax.swing.*;
class Text extends JFrame
{
    Text()
    {
        setTitle("My Notepad");
        JTextArea area = new JTextArea("Enter your comments here...",10,30);

        area.setLineWrap(true);
        area.setWrapStyleWord(true);

        JScrollPane scroll = new JScrollPane(area);
        add(scroll);

        setSize(400,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
public class GUI5 
{
    public static void main(String[] args)
    {
        new Text();
    }
    
}