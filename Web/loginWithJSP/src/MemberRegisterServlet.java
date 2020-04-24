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
		// �����͸� �޾Ƽ� ȸ�������� �Ѵ�.
		// ȸ�� ���� ���� ���θ� request��ü�� �����Ѵ�.
		// ȸ�� ���Կ� ���� �ÿ��� ȸ�� ��ü�� request��ü�� member��� �Ӽ������� �����Ѵ�.
		// ���� �ÿ��� member�Ӽ��� �������� �ʴ´�.
		
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