package member.service;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import member.dao.MemberDAO;
import member.exception.MemberException;
import member.vo.MemberVO;

import java.util.Calendar;
import java.text.SimpleDateFormat;

public class MemberInsertService implements IService
{
	private MemberDAO dao;
	
	public MemberInsertService()
	{
		dao = new MemberDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException, MemberException
	{
		MemberVO member = new MemberVO();
		String email = (String)request.getAttribute("email");
		String password = (String)request.getAttribute("password");
		String nick = (String)request.getAttribute("nick");
		
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		String regdate = sdf.format(cal.getTime());
		String picture = (String)request.getAttribute("picture");
		
		member.setEmail(email);
		member.setPassword(password);
		member.setNick(nick);
		member.setRegdate(regdate);
		member.setPicture(picture);
		
		dao.insert(member);
	}
}
