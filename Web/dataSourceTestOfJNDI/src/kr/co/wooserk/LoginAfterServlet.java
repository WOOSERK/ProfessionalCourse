package kr.co.wooserk;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import kr.co.wooserk.model.Member;

@WebServlet("/loginAfter")
public class LoginAfterServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		PrintWriter out = response.getWriter();

		HttpSession session = request.getSession(false);
		
		if(session == null)
		{
			out.println("로그인 상태가 아닙니다.");
		}
		else
		{
			Member m = (Member)session.getAttribute("member");
			if (m == null)
			{
				out.println("로그인 상태가 아닙니다.");
			}
			else
			{
				out.println("메일주소 : " + m.getEmail() + "<br />");
				out.println("별명 : " + m.getNick() + "<br />");
				out.println("가입일자 : " + m.getRegdate() + "<br />");
				out.println("탈퇴일자 : " + m.getRemoveAt() + "<br />");
			}
		}
	}
}
