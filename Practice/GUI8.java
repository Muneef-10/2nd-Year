import javax.swing.*;
class GUI8
{
    JFrame frame;
    GUI8()
    {
        frame=new JFrame("Select");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setLayout(null);

        JRadioButton male=new JRadioButton("MALE");
        male.setBounds(50,50,80,30);
        JRadioButton female=new JRadioButton("FEMALE");
        female.setBounds(50,80,80,30);
        JRadioButton none=new JRadioButton("NONE");
        none.setBounds(50,110,80,30);

        ButtonGroup bg=new ButtonGroup();
        bg.add(male);
        bg.add(female);
        bg.add(none);

        JButton btn=new JButton("SUBMIT");
        btn.setBounds(50,150,80,30);

        btn.addActionListener(e->{
            String msg="Selected";
            if(male.isSelected())
                msg+=":Male";
            if(female.isSelected())
                msg+=":Female";
            if(none.isSelected())
                msg+=":none";

            JOptionPane.showMessageDialog(frame,msg);
        });

        frame.add(male);
        frame.add(female);
        frame.add(none);
        frame.add(btn);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        new GUI8();
    }
}
