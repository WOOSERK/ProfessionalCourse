package member.service;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import member.dao.MemberDAO;
import member.exception.MemberException;
import member.vo.MemberVO;

public class MemberDeleteService implements IService
{
	private MemberDAO dao;
	
	public MemberDeleteService()
	{
		dao = new MemberDAO();
	}
	
	public void doService(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException, MemberException
	{
		MemberVO member = new MemberVO();
		
		
	}
}
