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
		// 요청 객체로부터 메일주소와 비밀번호를 추출한 후
		// 데이터베이스로부터 해당 정보를 검색합니다.
		// 해당 정보가 있다면 세션에 키이름 "member"로 member객체를 등록합니다.
		// 로그인이 완료된 후에는 login.jsp로 redirect 한다.
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
