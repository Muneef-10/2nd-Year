import javax.swing.*;
class GUI 
{
    JFrame frame;
    GUI()
    {
        frame=new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setLayout(null);

        JCheckBox cb1=new JCheckBox("JAVA");
        cb1.setBounds(50,50,80,30);

        JCheckBox cb2=new JCheckBox("PYTHON");
        cb2.setBounds(50,80,80,30);

        JButton btn=new JButton("SUBMIT");
        btn.setBounds(50,130,100,30);

        btn.addActionListener(e->{
            String msg="Selected";
            if(cb1.isSelected())
                msg+=": JAVA";
            if(cb2.isSelected())
                msg+=": PYTHON";

            JOptionPane.showMessageDialog(frame,msg);
        });

        frame.add(cb1);
        frame.add(cb2);
        frame.add(btn);
        frame.setVisible(true);

    }
}

class GUI6
{
    public static void main(String[] args) {
        new GUI();
    }
}