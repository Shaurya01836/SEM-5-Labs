import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DBAccess {

    // Your existing database connection method
    public static Connection connDB(String strURL, String strUser, String strPass) {
        Connection connection = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver"); // For modern MySQL versions
            connection = java.sql.DriverManager.getConnection(strURL, strUser, strPass);
            return connection;
        } catch (ClassNotFoundException | SQLException e) {
            throw new RuntimeException(e);
        }
    }

    // New method to validate user credentials
    public static boolean validateLogin(String username, String password) {
        // Replace with your database connection details
        String url = "jdbc:mysql://localhost:3306/College";
        String user = "root";
        String pass = "Shaurya@123";

        try (Connection conn = connDB(url, user, pass)) {
            String sql = "SELECT * FROM login WHERE username = ? AND pwd = ?";
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1, username);
            statement.setString(2, password);

            ResultSet rs = statement.executeQuery();
            return rs.next(); // If a record is found, returns true

        } catch (SQLException ex) {
            ex.printStackTrace();
            return false;
        }
    }

    public static void main(String[] args) {
        // You can leave this empty or use it for testing
    }
}