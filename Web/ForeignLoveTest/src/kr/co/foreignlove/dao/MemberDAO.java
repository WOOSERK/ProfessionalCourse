package kr.co.foreignlove.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.naming.NamingException;

import kr.co.foreignlove.controller.DBManager;
import kr.co.foreignlove.vo.MemberVO;

public class MemberDAO
{
	public MemberVO find(String id, String pass)
	{
		MemberVO member = null;
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		DBManager dbManager = new DBManager();
		
		try
		{
			con  = dbManager.getConnection();
			pstmt = con.prepareStatement("SELECT * FROM members WHERE email = ? AND pass = PASSWORD(?)");
			
			pstmt.setString(1, id);
			pstmt.setString(2, pass);
			
			rs = pstmt.executeQuery();
			
			if(rs.next())
			{
				member = new MemberVO(id, pass);
			}
		}
		catch(NamingException e)
		{
			e.printStackTrace();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			dbManager.close(rs, pstmt, con);
		}
		
		return member;
	}
}
