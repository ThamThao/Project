import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class register implements ActionListener {

    private JFrame res;
    private JTextField t1, t2, t3;
    private JButton b1, b2;

    public void reg() {
        res = new JFrame("Register");
        res.setSize(400, 150);
        res.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        res.setResizable(false);

        Font labelFont = new Font(Font.SANS_SERIF, Font.BOLD, 14);
        Font textFont = new Font(Font.SANS_SERIF, Font.BOLD, 12);

        JLabel name = new JLabel(" Username:");
        name.setFont(labelFont);
        t1 = new JTextField(15);
        t1.setFont(textFont);

        JLabel password = new JLabel(" Password:");
        password.setFont(labelFont);
        t2 = new JPasswordField();
        t2.setFont(textFont);

        JLabel password2 = new JLabel(" Confirm Password:");
        password2.setFont(labelFont);
        t3 = new JPasswordField();
        t3.setFont(textFont);

        b1 = new JButton("Confirm");
        b2 = new JButton("Cancel");
        b1.setBackground(Color.lightGray);
        b2.setBackground(Color.lightGray);

        JPanel insert = new JPanel(new GridLayout(3, 2, 5, 2));  
        insert.add(name);
        insert.add(t1);
        insert.add(password);
        insert.add(t2);
        insert.add(password2);
        insert.add(t3);

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(b1);
        buttonPanel.add(b2);

        res.add(insert, BorderLayout.CENTER);
        res.add(buttonPanel, BorderLayout.SOUTH);

        b1.addActionListener(this);
        b2.addActionListener(this);

        res.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String username1 = t1.getText();
        String pass1 = t2.getText();
        String pass2 = t3.getText();

        if (e.getSource() == b1) {
            new file(username1, pass1, pass2);
            res.dispose();
            new Login();
        } else if (e.getSource() == b2) {
            res.dispose();
            new Login();
        }
    }

    public static void main(String[] args) {
        new register().reg();
    }
}
