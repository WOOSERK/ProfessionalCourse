package kr.co.wooserk;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import kr.co.wooserk.dao.MemberDAO;
import kr.co.wooserk.model.Member;

@WebServlet("/list")
public class MemberListServlet extends HttpServlet
{
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html; charset=utf-8");
		
		PrintWriter out = response.getWriter();
		MemberDAO memberDAO = new MemberDAO();
		
		ArrayList<Member> memberList = memberDAO.getMemberList();
		
		for(Member m : memberList)
		{
			out.println("이메일 : " + m.getEmail()
					  + " 별명 : " + m.getNick()
			      //  + " 가입일자 : " + m.getRegdate().substring(0, 10)
					  + ( m.getRemoveAt() != null ? (" 탈퇴일자 : " + m.getRemoveAt().substring(0, 10) + "<br />") : "<br />"));
		}
	}
}
