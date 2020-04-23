package kr.co.wooserk;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.wooserk.dao.MemberDAO;
import kr.co.wooserk.model.Member;

@WebServlet("/register")
public class RegisterServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html; charset=utf-8"); 
		PrintWriter out = response.getWriter();
		
		String email = request.getParameter("email");
		String pass = request.getParameter("pass");
		String nick = request.getParameter("nick");
		
		MemberDAO memberDAO = new MemberDAO();
		Member m = new Member();
		
		m.setEmail(email);
		m.setPassword(pass);
		m.setNick(nick);
		
		if(memberDAO.insert(m))
		{
			out.println("회원가입에 성공하였습니다.");
			out.println("메일주소 : " + email + "<br />");
			out.println("별명 : " + nick + "<br />");
		}
		else
		{
			out.println("회원가입에 실패하였습니다.");
		}
	}
}
