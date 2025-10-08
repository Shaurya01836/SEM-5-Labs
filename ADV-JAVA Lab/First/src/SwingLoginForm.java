import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingLoginForm extends JFrame implements ActionListener {

    // Swing Components
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JButton loginButton, clearButton;
    private JToggleButton showPasswordToggle;
    private JCheckBox rememberMeCheckbox;


    public SwingLoginForm() {
        // --- Setting up the Application Window ---
        super("Swing Login Form");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Use a GridBagLayout for flexible and precise control
        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        // Set default constraints
        gbc.insets = new Insets(5, 5, 5, 5); // Add padding
        gbc.fill = GridBagConstraints.HORIZONTAL; // Make components fill horizontally

        // --- Creating and Adding Components ---

        // Username Label and Field
        gbc.gridx = 0; // Column 0
        gbc.gridy = 0; // Row 0
        gbc.anchor = GridBagConstraints.EAST; // Right-align the label
        add(new JLabel("Username:"), gbc);

        gbc.gridx = 1; // Column 1
        gbc.gridy = 0;
        gbc.weightx = 1.0; // Give this column extra space
        add(usernameField = new JTextField(20), gbc);

        // Password Label and Field
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.weightx = 0;
        add(new JLabel("Password:"), gbc);

        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.weightx = 1.0;
        add(passwordField = new JPasswordField(20), gbc);

        // Checkbox and Toggle Button
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.gridwidth = 1; // Spans 1 column
        add(rememberMeCheckbox = new JCheckBox("Remember Me"), gbc);

        gbc.gridx = 1;
        gbc.gridy = 2;
        add(showPasswordToggle = new JToggleButton("Show Password"), gbc);
        showPasswordToggle.addActionListener(this);

        // Buttons
        gbc.gridx = 0;
        gbc.gridy = 3; // Shifted up from row 4
        gbc.gridwidth = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        add(loginButton = new JButton("Login"), gbc);
        loginButton.addActionListener(this);

        gbc.gridx = 1;
        gbc.gridy = 3; // Shifted up from row 4
        add(clearButton = new JButton("Clear"), gbc);
        clearButton.addActionListener(this);

        // Finish layout setup
        setSize(400, 200);
        setLocationRelativeTo(null); // Centers the window
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();

        if (source == loginButton) {
            // Minimized login logic remains: just a message
            JOptionPane.showMessageDialog(this,
                    "Login functionality not available yet.",
                    "Feature Status", JOptionPane.INFORMATION_MESSAGE);

        } else if (source == clearButton) {
            usernameField.setText("");
            passwordField.setText("");
            rememberMeCheckbox.setSelected(false);

        } else if (source == showPasswordToggle) {
            if (showPasswordToggle.isSelected()) {
                passwordField.setEchoChar((char) 0); // Show text
            } else {
                passwordField.setEchoChar('*'); // Hide text
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SwingLoginForm());
    }
}