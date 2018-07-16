package db;
//12161520 컴퓨터공학과 강지수
import java.sql.*;

public class jdbc {
	public static void main(String[] args) throws SQLException {
		
try {
Connection con=null;
Statement stmt=null;
try{
	Class.forName("com.mysql.jdbc.Driver");
	String url = "jdbc:mysql://localhost:3306/university";
	con = DriverManager.getConnection(url,"root","kjs425");
}
catch (Exception e){
	System.out.println("데이터베이스 접속에 문제가 있습니다.");
	System.out.println(e.getMessage());
	e.printStackTrace();
}

stmt=con.createStatement();
String sql = "select * from instructor";
ResultSet rs = stmt.executeQuery(sql);

System.out.println("  ID    name   dept_name   salary  ");
while(rs.next()){
	System.out.print(rs.getString("ID")+ " ");
	System.out.print(rs.getString("name")+ " ");
	System.out.print(rs.getString("dept_name")+ " ");
	System.out.println(rs.getString("salary"));
}

//stmt.executeUpdate("delete from instructor where ID='77988';");
stmt.executeUpdate("insert into instructor values('77988','Kang','Physics',98000)");


System.out.println("\n--insert--\n");
stmt=con.createStatement();
sql = "select * from instructor";
rs = stmt.executeQuery(sql);

System.out.println("  ID    name   dept_name   salary  ");
while(rs.next()){
	System.out.print(rs.getString("ID")+ " ");
	System.out.print(rs.getString("name")+ " ");
	System.out.print(rs.getString("dept_name")+ " ");
	System.out.println(rs.getString("salary"));
}

/*System.out.println("\n--aggregation--\n");
ResultSet rset = stmt.executeQuery("select dept_name, avg(salary) from instructor group by dept_name");
while(rset.next()) {
	System.out.println(rset.getString("dept_name")+" " + rset.getFloat(2));
}*/

rs.close();
stmt.close();
con.close();
}
catch(Exception sqle) {
	System.out.println("Exception:"+sqle);
}
	}
}
