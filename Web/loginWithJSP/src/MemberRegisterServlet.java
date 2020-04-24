import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.wooserk.dao.MemberDAO;
import kr.co.wooserk.vo.Member;

@WebServlet("/registerMember")
public class MemberRegisterServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// 데이터를 받아서 회원가입을 한다.
		// 회원 가입 성공 여부를 request객체에 저장한다.
		// 회원 가입에 성공 시에는 회원 객체를 request객체에 member라는 속성명으로 저장한다.
		// 실패 시에는 member속성을 저장하지 않는다.
		
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		String nick = request.getParameter("nick");
		
		if(MemberDAO.insert(email, password, nick))
		{
			request.setAttribute("result", "true");
			Member m = MemberDAO.search(email, password);
			request.setAttribute("member", m);
			response.sendRedirect("register.jsp?result=true");
		}
		else
		{
			request.setAttribute("result", "false");
			response.sendRedirect("register.jsp?result=false");
		}
		
		//response.sendRedirect("register.jsp");
		//RequestDispatcher disp = request.getRequestDispatcher("register.jsp");
		//disp.forward(request, response);
	}
}