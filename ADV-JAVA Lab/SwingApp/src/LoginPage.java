import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class LoginPage extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JComboBox<String> usertypeBox;
    private JLabel errorMsg;

    // --- Define styles ---
    private static final Color BG_COLOR = new Color(245, 245, 245);
    private static final Color PRIMARY_COLOR = new Color(0, 120, 215);
    private static final Color PRIMARY_HOVER_COLOR = new Color(0, 100, 185); // Darker blue
    private static final Color TEXT_COLOR = new Color(30, 30, 30);
    private static final Color ERROR_COLOR = Color.RED;
    private static final Color SECONDARY_BUTTON_COLOR = new Color(230, 230, 230);
    private static final Color SECONDARY_HOVER_COLOR = new Color(215, 215, 215); // Darker gray

    private static final Font FONT_LABEL = new Font("Segoe UI", Font.BOLD, 14);
    private static final Font FONT_FIELD = new Font("Segoe UI", Font.PLAIN, 14);
    private static final Font FONT_BUTTON = new Font("Segoe UI", Font.BOLD, 12);
    private static final Font FONT_ERROR = new Font("Segoe UI", Font.ITALIC, 12);

    private static final Border FIELD_PADDING = BorderFactory.createEmptyBorder(5, 5, 5, 5);
    private static final Dimension FIELD_DIMENSION = new Dimension(200, 28);


    public LoginPage() {
        // --- Look and Feel is set in Main.java ---

        setTitle("Login Page");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 320); // Increased size
        setLayout(new BorderLayout());

        JPanel panel = new JPanel(new GridBagLayout());
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20)); // Increased padding
        panel.setBackground(BG_COLOR);
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(8, 8, 8, 8); // Increased insets
        gbc.fill = GridBagConstraints.HORIZONTAL;

        JLabel userLabel = new JLabel("Username:");
        userLabel.setFont(FONT_LABEL);
        userLabel.setForeground(TEXT_COLOR);

        usernameField = new JTextField(15);
        usernameField.setFont(FONT_FIELD);
        usernameField.setBorder(FIELD_PADDING);
        usernameField.setPreferredSize(FIELD_DIMENSION);

        JLabel passLabel = new JLabel("Password:");
        passLabel.setFont(FONT_LABEL);
        passLabel.setForeground(TEXT_COLOR);

        passwordField = new JPasswordField(15);
        passwordField.setFont(FONT_FIELD);
        passwordField.setBorder(FIELD_PADDING);
        passwordField.setPreferredSize(FIELD_DIMENSION);

        JLabel typeLabel = new JLabel("User Type:");
        typeLabel.setFont(FONT_LABEL);
        typeLabel.setForeground(TEXT_COLOR);

        usertypeBox = new JComboBox<>(new String[]{"admin", "user", "guest"});
        usertypeBox.setFont(FONT_FIELD);
        usertypeBox.setPreferredSize(FIELD_DIMENSION);

        errorMsg = new JLabel(" "); // Add space to hold layout
        errorMsg.setFont(FONT_ERROR);
        errorMsg.setForeground(ERROR_COLOR);

        JButton loginBtn = new JButton("Login");
        stylePrimaryButton(loginBtn);

        JButton goRegisterBtn = new JButton("Register");
        styleSecondaryButton(goRegisterBtn);

        // --- Layout components ---
        gbc.gridx = 0; gbc.gridy = 0; gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(userLabel, gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        panel.add(usernameField, gbc);

        gbc.gridx = 0; gbc.gridy = 1; gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(passLabel, gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        panel.add(passwordField, gbc);

        gbc.gridx = 0; gbc.gridy = 2; gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(typeLabel, gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        panel.add(usertypeBox, gbc);

        gbc.gridx = 1; gbc.gridy = 3; gbc.anchor = GridBagConstraints.LINE_START;
        gbc.gridwidth = 2;
        panel.add(errorMsg, gbc);

        gbc.gridx = 0; gbc.gridy = 4; gbc.gridwidth = 2; gbc.anchor = GridBagConstraints.CENTER;
        gbc.fill = GridBagConstraints.NONE;
        JPanel btnPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        btnPanel.setBackground(BG_COLOR);
        btnPanel.add(loginBtn);
        btnPanel.add(goRegisterBtn);
        panel.add(btnPanel, gbc);

        add(panel, BorderLayout.CENTER);

        // --- Event Listeners ---
        loginBtn.addActionListener(e -> doLogin());
        goRegisterBtn.addActionListener(e -> {
            dispose();
            new RegisterPage();
        });

        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void stylePrimaryButton(JButton btn) {
        btn.setFont(FONT_BUTTON);
        btn.setBackground(PRIMARY_COLOR);
        btn.setForeground(Color.WHITE);
        btn.setFocusPainted(false);
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setOpaque(true);
        btn.setBorderPainted(false); // *** THE FIX ***
        btn.setBorder(BorderFactory.createEmptyBorder(8, 20, 8, 20)); // Our padding

        // Add hover effect
        btn.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) {
                btn.setBackground(PRIMARY_HOVER_COLOR);
            }
            public void mouseExited(MouseEvent evt) {
                btn.setBackground(PRIMARY_COLOR);
            }
        });
    }

    private void styleSecondaryButton(JButton btn) {
        btn.setFont(FONT_BUTTON);
        btn.setBackground(SECONDARY_BUTTON_COLOR);
        btn.setForeground(TEXT_COLOR);
        btn.setFocusPainted(false);
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setOpaque(true);
        btn.setBorderPainted(false); // *** THE FIX ***
        btn.setBorder(BorderFactory.createEmptyBorder(8, 20, 8, 20)); // Our padding

        // Add hover effect
        btn.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) {
                btn.setBackground(SECONDARY_HOVER_COLOR);
            }
            public void mouseExited(MouseEvent evt) {
                btn.setBackground(SECONDARY_BUTTON_COLOR);
            }
        });
    }

    private void doLogin() {
        // (This method is unchanged)
        String username = usernameField.getText().trim();
        String password = String.valueOf(passwordField.getPassword()).trim();
        String usertype = usertypeBox.getSelectedItem().toString();

        if (username.isEmpty() || password.isEmpty()) {
            errorMsg.setText("Please fill all fields.");
            return;
        }
        errorMsg.setText(" ");

        String sql = "SELECT 1 FROM login WHERE username = ? AND password = ? AND usertype = ? AND isActive = 1";
        boolean loginSuccess = false;

        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            pstmt.setString(2, password);
            pstmt.setString(3, usertype);

            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    loginSuccess = true;
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
            errorMsg.setText("Database error. Please try again.");
        }

        if (loginSuccess) {
            if (usertype.equals("admin")) {
                JOptionPane.showMessageDialog(this, "Admin login successful! Opening User Management.");
                dispose();
                new UserManagementPage();
            } else {
                JOptionPane.showMessageDialog(this, "Login successful! Welcome, " + username);
            }
        } else {
            errorMsg.setText("Invalid credentials, user type, or user is inactive.");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(LoginPage::new);
    }
}