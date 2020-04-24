package kr.co.wooserk.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.naming.NamingException;

import kr.co.wooserk.controller.DBController;
import kr.co.wooserk.vo.Member;

public class MemberDAO 
{
	public static boolean insert(String email, String password, String nick)
	{
		boolean result = false;
		Connection con = null;
		PreparedStatement pstmt = null;
		try
		{
			con = DBController.getConnection();
			pstmt = con.prepareStatement("INSERT INTO members(email, pass, nick) VALUES(?, PASSWORD(?), ?);");
			pstmt.setString(1, email);
			pstmt.setString(2, password);
			pstmt.setString(3, nick);
			if(pstmt.executeUpdate() > 0)
			{
				result =  true;
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
			DBController.close(pstmt, con);
		}
	
		return result;
	}
	
	public static Member search(String email, String password)
	{
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		Member m = null;
		
		try
		{
			con = DBController.getConnection();	
			pstmt = con.prepareStatement("SELECT * FROM members WHERE email = ? AND pass = PASSWORD(?)");
			pstmt.setString(1, email);
			pstmt.setString(2, password);
			
			rs = pstmt.executeQuery();
			
			if(rs.next())
			{
				m = new Member(rs.getString("email")
						, rs.getString("pass")
						, rs.getString("nick")
						, rs.getString("regdate")
						, rs.getString("remove_at"));
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
			DBController.close(rs, pstmt, con);
		}
		
		return m;
	}
}
