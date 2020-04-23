package kr.co.wooserk;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import kr.co.wooserk.dao.MemberDAO;
import kr.co.wooserk.model.Member;

@WebServlet("/login")
public class LoginServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html; charset=utf-8");
		PrintWriter out = response.getWriter();
		
		String email = request.getParameter("email");
		String pass = request.getParameter("pass");
		
		MemberDAO memberDAO = new MemberDAO();
		Member member = memberDAO.search(email, pass);
		
		if (member == null)
		{
			out.println("�������� �ʴ� �����ּ��̰ų� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.");
		}
		else
		{
			HttpSession session = request.getSession();
			session.setAttribute("member", member);
			RequestDispatcher disp = request.getRequestDispatcher("/loginAfter");
			disp.forward(request, response);
		}
	}
}
