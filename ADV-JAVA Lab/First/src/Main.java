import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {

        JFrame jf = new JFrame("Login page");
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setSize(400, 400);
        jf.getContentPane().setBackground(Color.DARK_GRAY);

        jf.setLayout(new GridBagLayout());
        GridBagConstraints gc = new GridBagConstraints();
        gc.insets = new Insets(5, 5, 5, 5);
        gc.fill = GridBagConstraints.HORIZONTAL;


        JLabel usernameLabel = new JLabel("Username:");
        usernameLabel.setForeground(Color.WHITE);
        JTextField username = new JTextField(15);
        JLabel passwordLabel = new JLabel("Password:");
        passwordLabel.setForeground(Color.WHITE);
        JPasswordField password = new JPasswordField(15);
        JButton login = new JButton("Login");
        login.setBackground(Color.cyan);
        JButton forget = new JButton("Forgot password !!");

        login.setFocusable(false);

        // Add ActionListener to the login button
        login.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String user = username.getText();
                String pass = new String(password.getPassword());

                // Call the validation method from DBAccess
                if (DBAccess.validateLogin(user, pass)) {
                    JOptionPane.showMessageDialog(jf, "Login Successful!");
                } else {
                    JOptionPane.showMessageDialog(jf, "Invalid Credentials!", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });


        // Row 0, Column 0
        gc.gridx = 0;
        gc.gridy = 0;
        jf.add(usernameLabel, gc);

        // Row 0, Column 1
        gc.gridx = 1;
        gc.gridy = 0;
        jf.add(username, gc);

        // Row 1, Column 0
        gc.gridx = 0;
        gc.gridy = 1;
        jf.add(passwordLabel, gc);

        // Row 1, Column 1
        gc.gridx = 1;
        gc.gridy = 1;
        jf.add(password, gc);

        // Row 2, Column 0
        gc.gridx = 0;
        gc.gridy = 2;
        jf.add(login, gc);

        // Row 2, Column 1
        gc.gridx = 1;
        gc.gridy = 2;
        jf.add(forget, gc);

        jf.setVisible(true);
    }
}