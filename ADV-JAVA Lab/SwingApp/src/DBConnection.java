import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    private static final String URL = "jdbc:mysql://localhost:3306/swing";
    private static final String USER = "root";
    private static final String PASS = "Shaurya@123";

    public static Connection getConnection() throws SQLException {

        Connection conn = DriverManager.getConnection(URL, USER, PASS);
        return conn;
    }


    public static void main(String[] args) {
        try {
            Connection conn = DBConnection.getConnection();
            if (conn != null) {
                System.out.println("MySQL database connected successfully!");
                conn.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
