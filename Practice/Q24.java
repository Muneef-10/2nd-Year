import javax.swing.*;
public class Q24 
{
    JFrame frame;
    Q24()
    {
        frame=new JFrame("Count");
        frame.setSize(500,500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JLabel lb1=new JLabel("Enter string");
        lb1.setBounds(30,30,80,30);

        JTextField text1=new JTextField();
        text1.setBounds(130,30,80,30);

        JLabel lb2=new JLabel("Result");
        lb2.setBounds(30,80,80,30);

        JTextField text2=new JTextField();
        text2.setBounds(150,80,80,30);
        text2.setEditable(false);

        JButton count=new JButton("Count");
        count.setBounds(50,120,50,30);
        JButton reset=new JButton("Reset");
        reset.setBounds(110,120,50,30);
        JButton exit=new JButton("Exit");
        exit.setBounds(170,120,50,30);

        count.addActionListener(e->{
            String text=text1.getText().toLowerCase();
            int c=0;
            for(char ch: text.toCharArray())
            {
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') c++;

            }
            text2.setText(""+c);
        });
        reset.addActionListener(e->{
            
            text1.setText("");
            text2.setText("");
        });
        exit.addActionListener(e->{
            System.exit(0);
        });
        frame.add(lb1);
        frame.add(text1);
        frame.add(lb2);
        frame.add(text2);
        frame.add(count);
        frame.add(reset);
        frame.add(exit);
        frame.setVisible(true);

    }
    public static void main(String[] args) {
        new Q24();
    }    
}
