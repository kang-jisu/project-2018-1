

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



@SuppressWarnings("serial")
public class UserServlet extends HttpServlet {
	UserDao ud = new UserDaoImpl();
	ClassesDao cd = new ClassesDaoImpl();

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html");
		response.setCharacterEncoding("UTF-8");
		request.setCharacterEncoding("UTF-8");
		String type = request.getParameter("type");
		if (type.equals("all")) {
			doAll(request, response);
		} else if (type.equals("del")) {
			doDel(request, response);
		} else if (type.equals("upd")) {
			doUpd(request, response);
		} else if (type.equals("add")) {
			doAdd(request, response);
		}
	}

	public void doAdd(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
	
	}

	public void doUpd(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

	}

	public void doDel(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

	}

	public void doAll(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		int index = 1;
		String strs = request.getParameter("index");
		if (strs != null) {
			index = Integer.parseInt(strs);
		}
		PageUtil<User> page = new PageUtil<User>();
		page.setIndex(index);
		ud.selectAll(page);
		request.setAttribute("page", page);
		request.setAttribute("index", page.getIndex());
		request.setAttribute("sum", page.pageCount(page.getCount(), page
				.getSize()));
		request.getRequestDispatcher("index.jsp").forward(request, response);
	}
}