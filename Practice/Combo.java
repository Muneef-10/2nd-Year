import java.awt.*;

import javax.swing.*;
public class Combo 
{
    JFrame frame;
    Combo()
    {
        frame=new JFrame("COMBO");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);

        String []countries={"India","U.S","Japan","France"};
        String []capitals={"New delhi","Washington","Tokyo","Paris"};

        JComboBox<String> country=new JComboBox<>(countries);
        JComboBox<String> capital=new JComboBox<>(capitals);

        JLabel lb1=new JLabel("Select Country");
        lb1.setBounds(30,30,60,30);

        JLabel lb2=new JLabel("Select Capital");
        lb2.setBounds(30,80,60,30);

        country.setBounds(100,30,80,30);
        capital.setBounds(100,80,80,30);

        JButton btn=new JButton("SUBMIT");
        btn.setBounds(50,120,80,30);

        JLabel lb3=new JLabel("");
        lb3.setBounds(50,160,80,30);

        btn.addActionListener(e->{
            String ctry=(String) country.getSelectedItem();
            String captl=(String) capital.getSelectedItem();
            int index=-1;
            for(int i=0;i<countries.length;i++)
            {
                if(countries[i].equals(ctry))
                {
                    index =i;
                    break;
                }
            }
            if(capitals[index].equals(captl))
            {
                
                lb3.setForeground(Color.GREEN);
                lb3.setText("Correct");
            }
            else 
            {
                lb3.setForeground(Color.RED);
                lb3.setText("Incorrect, correct is "+capitals[index]);
            }
        });

        frame.add(lb1);
        frame.add(country);
        frame.add(lb2);
        frame.add(capital);
        frame.add(btn);
        frame.add(lb3);
        frame.setVisible(true);

    }    
    public static void main(String[] args) {
        new Combo();
    }
}
