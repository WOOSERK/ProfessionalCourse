import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import kr.co.wooserk.dao.MemberDAO;
import kr.co.wooserk.vo.Member;

@WebServlet("/login")
public class LoginServlet extends HttpServlet 
{
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// ��û ��ü�κ��� �����ּҿ� ��й�ȣ�� ������ ��
		// �����ͺ��̽��κ��� �ش� ������ �˻��մϴ�.
		// �ش� ������ �ִٸ� ���ǿ� Ű�̸� "member"�� member��ü�� ����մϴ�.
		// �α����� �Ϸ�� �Ŀ��� login.jsp�� redirect �Ѵ�.
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		
		Member m = MemberDAO.search(email, password);
		if(m != null)
		{
			HttpSession session = request.getSession();
			session.setAttribute("member", m);
		}		
		response.sendRedirect("login.jsp");
	}
}
