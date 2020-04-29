package member.service;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import member.dao.MemberDAO;
import member.exception.MemberException;
import member.vo.MemberVO;

public class MemberUpdateService implements IService
{
	private MemberDAO dao;
	
	public MemberUpdateService()
	{
		dao = new MemberDAO();	
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException, MemberException
	{
		String email = (String)request.getAttribute("email");
		String nick = (String)request.getAttribute("nick");
		String password = (String)request.getAttribute("password");
		String picture = (String)request.getAttribute("picture");
		
		MemberVO m = new MemberVO();
		
		m.setEmail(email);
		m.setNick(nick);
		m.setPassword(password);
		m.setPicture(picture);
		
		dao.update(m);
	}
}
