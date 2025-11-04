import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserManagementPage extends JFrame {

    // --- Define styles ---
    private static final Color BG_COLOR = new Color(245, 245, 245);
    private static final Color PRIMARY_COLOR = new Color(0, 120, 215);
    private static final Color PRIMARY_HOVER_COLOR = new Color(0, 100, 185);
    private static final Color TEXT_COLOR = new Color(30, 30, 30);
    private static final Color ERROR_COLOR = Color.RED;
    private static final Color SECONDARY_BUTTON_COLOR = new Color(230, 230, 230);
    private static final Color SECONDARY_HOVER_COLOR = new Color(215, 215, 215);
    private static final Color DEACTIVATE_COLOR = new Color(220, 53, 69);
    private static final Color DEACTIVATE_HOVER_COLOR = new Color(200, 45, 60);

    private static final Font FONT_LABEL = new Font("Segoe UI", Font.BOLD, 14);
    private static final Font FONT_FIELD = new Font("Segoe UI", Font.PLAIN, 14);
    private static final Font FONT_BUTTON = new Font("Segoe UI", Font.BOLD, 12);

    private JTable userTable;
    private DefaultTableModel tableModel;
    private JTextField passwordField;
    private JComboBox<String> usertypeBox;
    private JCheckBox isActiveCheckBox;
    private JLabel usernameLabel;
    private JButton updateBtn;
    private JButton deactivateBtn;
    private JButton logoutBtn;

    public UserManagementPage() {
        // --- Look and Feel is now set in Main.java ---

        setTitle("User Management (Admin)");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 600);
        setLayout(new BorderLayout(10, 10));
        getContentPane().setBackground(BG_COLOR);
        getRootPane().setBorder(new EmptyBorder(10, 10, 10, 10));

        // --- 1. User Table Panel (Top) ---
        JPanel tablePanel = createTablePanel();
        add(tablePanel, BorderLayout.CENTER);

        // --- 2. Edit Form Panel (Bottom) ---
        JPanel editPanel = createEditPanel();
        add(editPanel, BorderLayout.SOUTH);

        // --- Load data ---
        loadAllUsers();

        setLocationRelativeTo(null);
        setVisible(true);
    }

    private JPanel createTablePanel() {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setBackground(Color.WHITE);
        panel.setBorder(BorderFactory.createTitledBorder(
                BorderFactory.createLineBorder(Color.LIGHT_GRAY), "All Users"));

        String[] columnNames = {"Username", "User Type", "Status"};
        tableModel = new DefaultTableModel(columnNames, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        userTable = new JTable(tableModel);
        userTable.setFont(FONT_FIELD);
        userTable.getTableHeader().setFont(FONT_LABEL);
        userTable.setRowHeight(25);
        userTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        userTable.getSelectionModel().addListSelectionListener(e -> {
            if (!e.getValueIsAdjusting() && userTable.getSelectedRow() != -1) {
                int selectedRow = userTable.getSelectedRow();
                String username = tableModel.getValueAt(selectedRow, 0).toString();
                loadUserDataForEditing(username);
            }
        });

        JScrollPane scrollPane = new JScrollPane(userTable);
        panel.add(scrollPane, BorderLayout.CENTER);
        return panel;
    }

    private JPanel createEditPanel() {
        JPanel panel = new JPanel(new GridBagLayout());
        panel.setBackground(BG_COLOR);
        panel.setBorder(BorderFactory.createTitledBorder("Edit Selected User"));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(8, 8, 8, 8);
        gbc.anchor = GridBagConstraints.LINE_END;

        gbc.gridx = 0; gbc.gridy = 0;
        panel.add(new JLabel("Username:"), gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        usernameLabel = new JLabel("Please select a user from the table");
        usernameLabel.setFont(FONT_LABEL);
        panel.add(usernameLabel, gbc);

        gbc.gridx = 0; gbc.gridy = 1; gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(new JLabel("Password:"), gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        passwordField = new JTextField(15);
        passwordField.setFont(FONT_FIELD);
        panel.add(passwordField, gbc);

        gbc.gridx = 0; gbc.gridy = 2; gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(new JLabel("User Type:"), gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        usertypeBox = new JComboBox<>(new String[]{"admin", "user", "guest"});
        usertypeBox.setFont(FONT_FIELD);
        panel.add(usertypeBox, gbc);

        gbc.gridx = 0; gbc.gridy = 3; gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(new JLabel("Active:"), gbc);
        gbc.gridx = 1; gbc.anchor = GridBagConstraints.LINE_START;
        isActiveCheckBox = new JCheckBox("User is active");
        isActiveCheckBox.setFont(FONT_FIELD);
        isActiveCheckBox.setBackground(BG_COLOR);
        panel.add(isActiveCheckBox, gbc);

        updateBtn = new JButton("Update User");
        deactivateBtn = new JButton("Deactivate User");
        logoutBtn = new JButton("Logout");

        stylePrimaryButton(updateBtn);
        styleDeactivateButton(deactivateBtn);
        styleSecondaryButton(logoutBtn);

        JPanel btnPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 0));
        btnPanel.setBackground(BG_COLOR);
        btnPanel.add(updateBtn);
        btnPanel.add(deactivateBtn);
        btnPanel.add(logoutBtn);

        gbc.gridx = 0; gbc.gridy = 4; gbc.gridwidth = 2; gbc.anchor = GridBagConstraints.CENTER;
        panel.add(btnPanel, gbc);

        setEditFieldsEnabled(false);

        updateBtn.addActionListener(e -> updateUser());
        deactivateBtn.addActionListener(e -> deactivateUser());
        logoutBtn.addActionListener(e -> {
            dispose();
            new LoginPage();
        });

        return panel;
    }

    private void loadAllUsers() {
        tableModel.setRowCount(0);

        String sql = "SELECT username, usertype, isActive FROM login";
        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql);
             ResultSet rs = pstmt.executeQuery()) {

            while (rs.next()) {
                String username = rs.getString("username");
                String usertype = rs.getString("usertype");
                String status = rs.getInt("isActive") == 1 ? "Active" : "Inactive";
                tableModel.addRow(new Object[]{username, usertype, status});
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error loading users: " + e.getMessage(),
                    "Database Error", JOptionPane.ERROR_MESSAGE);
        }
        clearAndDisableEditPanel();
    }

    private void loadUserDataForEditing(String username) {
        String sql = "SELECT password, usertype, isActive FROM login WHERE username = ?";
        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                usernameLabel.setText(username);
                passwordField.setText(rs.getString("password"));
                usertypeBox.setSelectedItem(rs.getString("usertype"));
                isActiveCheckBox.setSelected(rs.getInt("isActive") == 1);

                setEditFieldsEnabled(true);
                if (username.equals("admin")) {
                    deactivateBtn.setEnabled(false);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error fetching user data: " + e.getMessage(),
                    "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void updateUser() {
        String username = usernameLabel.getText();
        String newPassword = passwordField.getText().trim();
        String newUserType = usertypeBox.getSelectedItem().toString();
        int isActive = isActiveCheckBox.isSelected() ? 1 : 0;

        if (username.equals("Please select a user from the table")) {
            return;
        }
        if (newPassword.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Password cannot be empty.", "Validation Error", JOptionPane.WARNING_MESSAGE);
            return;
        }

        String sql = "UPDATE login SET password = ?, usertype = ?, isActive = ? WHERE username = ?";
        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, newPassword);
            pstmt.setString(2, newUserType);
            pstmt.setInt(3, isActive);
            pstmt.setString(4, username);

            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(this, "User updated successfully!");
                loadAllUsers();
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error updating user: " + e.getMessage(),
                    "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void deactivateUser() {
        String username = usernameLabel.getText();
        if (username.equals("Please select a user from the table")) {
            return;
        }

        int confirm = JOptionPane.showConfirmDialog(this,
                "Are you sure you want to DEACTIVATE user '" + username + "'? (Sets isActive = 0)",
                "Confirm Deactivation", JOptionPane.YES_NO_OPTION);

        if (confirm != JOptionPane.YES_OPTION) {
            return;
        }

        String sql = "UPDATE login SET isActive = 0 WHERE username = ?";
        try (Connection conn = DBConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(this, "User deactivated successfully!");
                loadAllUsers();
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error deactivating user: " + e.getMessage(),
                    "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void setEditFieldsEnabled(boolean enabled) {
        passwordField.setEnabled(enabled);
        usertypeBox.setEnabled(enabled);
        isActiveCheckBox.setEnabled(enabled);
        updateBtn.setEnabled(enabled);
        deactivateBtn.setEnabled(enabled);
    }

    private void clearAndDisableEditPanel() {
        usernameLabel.setText("Please select a user from the table");
        passwordField.setText("");
        usertypeBox.setSelectedIndex(0);
        isActiveCheckBox.setSelected(false);
        setEditFieldsEnabled(false);
    }

    // --- Button Styling Methods ---
    private void stylePrimaryButton(JButton btn) {
        btn.setFont(FONT_BUTTON);
        btn.setBackground(PRIMARY_COLOR);
        btn.setForeground(Color.WHITE);
        btn.setFocusPainted(false);
        btn.setBorder(BorderFactory.createEmptyBorder(8, 20, 8, 20));
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setOpaque(true);

        btn.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) { btn.setBackground(PRIMARY_HOVER_COLOR); }
            public void mouseExited(MouseEvent evt) { btn.setBackground(PRIMARY_COLOR); }
        });
    }

    private void styleSecondaryButton(JButton btn) {
        btn.setFont(FONT_BUTTON);
        btn.setBackground(SECONDARY_BUTTON_COLOR);
        btn.setForeground(TEXT_COLOR);
        btn.setFocusPainted(false);
        btn.setBorder(BorderFactory.createEmptyBorder(8, 20, 8, 20));
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setOpaque(true);

        btn.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) { btn.setBackground(SECONDARY_HOVER_COLOR); }
            public void mouseExited(MouseEvent evt) { btn.setBackground(SECONDARY_BUTTON_COLOR); }
        });
    }

    private void styleDeactivateButton(JButton btn) {
        btn.setFont(FONT_BUTTON);
        btn.setBackground(DEACTIVATE_COLOR);
        btn.setForeground(Color.WHITE);
        btn.setFocusPainted(false);
        btn.setBorder(BorderFactory.createEmptyBorder(8, 20, 8, 20));
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setOpaque(true);

        btn.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) { btn.setBackground(DEACTIVATE_HOVER_COLOR); }
            public void mouseExited(MouseEvent evt) { btn.setBackground(DEACTIVATE_COLOR); }
        });
    }
}