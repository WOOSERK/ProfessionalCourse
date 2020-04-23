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

@WebServlet("/withdrawal")
public class WithdrawalServlet extends HttpServlet
{
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html; charset=utf-8"); 
		
		PrintWriter out = response.getWriter();
		String email = request.getParameter("email");
		MemberDAO memberDAO = new MemberDAO();
		Member m = new Member();
		m.setEmail(email);
		
		if(memberDAO.delete(m))
		{
			out.println("회원탈퇴에 성공하였습니다.");
		}
		else
		{
			out.println("회원탈퇴에 실패하였습니다.");
		}
	}
}
