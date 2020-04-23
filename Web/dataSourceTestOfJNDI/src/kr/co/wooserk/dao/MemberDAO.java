package kr.co.wooserk.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import javax.naming.NamingException;

import kr.co.wooserk.controller.DBController;
import kr.co.wooserk.model.Member;

public class MemberDAO
{
	/* 회원 가입 메서드 */
	public boolean insert(Member m)
	{
		boolean result = false;
		
		Connection con = null;
		PreparedStatement pstmt = null;
		
		try
		{
			con = DBController.getConnection();
			pstmt = con.prepareStatement("INSERT INTO members(email, pass, nick) VALUES(?, PASSWORD(?), ?)");
			pstmt.setString(1, m.getEmail());
			pstmt.setString(2, m.getPassword());
			pstmt.setString(3, m.getNick());
			
			if(pstmt.executeUpdate() > 0)
			{
				return true;
			}
			else
			{
				return false;
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
	
	/* 회원 탈퇴 메서드 */
	public boolean delete(Member m)
	{
		boolean result = false;
		
		Connection con = null;
		PreparedStatement pstmt = null;
		
		try
		{
			con = DBController.getConnection();
			pstmt = con.prepareStatement("UPDATE members SET remove_at = current_timestamp() WHERE email = ?");
			pstmt.setString(1, m.getEmail());
			
			if(pstmt.executeUpdate() > 0)
			{
				return true;
			}
			else
			{
				return false;
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
	
	/* 회원 조회 메서드 */
	public Member search(String email, String password)
	{
		Member m = null;
		
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		
		try
		{
			con = DBController.getConnection();
			stmt = con.createStatement();
			rs = stmt.executeQuery("SELECT * FROM members WHERE email='" + email + "' AND pass = PASSWORD('" + password + "')");
			if(rs.next())
			{
				m = new Member();
				m.setEmail(rs.getString("email"));
				m.setNick(rs.getString("nick"));
				m.setPassword(rs.getString("pass"));
				m.setRegdate(rs.getString("regdate"));
				m.setRemoveAt(rs.getString("remove_at"));
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
			DBController.close(rs, stmt, con);
		}
		
		return m;
	}
	
	/* 회원 목록 가져오기 */
	public ArrayList<Member> getMemberList()
	{
		ArrayList<Member> list = new ArrayList<>();
		
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		
		try
		{
			con = DBController.getConnection();
			stmt = con.createStatement();
			rs = stmt.executeQuery("SELECT * FROM members");
			
			while(rs.next())
			{
				list.add(new Member(rs.getString("email"), 
									rs.getString("nick"), 
									rs.getString("pass"),
									rs.getString("regdate"), 
									rs.getString("remove_at")));
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
			DBController.close(rs, stmt, con);
		}
		
		return list;
	}
}
