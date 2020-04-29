package member.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.naming.NamingException;

import member.controller.DBManager;
import member.exception.LoginFailedException;
import member.exception.MemberException;
import member.exception.MemberInsertException;
import member.exception.MemberUpdateException;
import member.vo.MemberVO;

public class MemberDAO
{
	public void update(MemberVO m) throws MemberException
	{
		String sql = "UPDATE members SET pass = PASSWORD(?), nick = ?, picture = ? WHERE email = ?";
		Connection con = null;
		PreparedStatement pstmt = null;
		
		try
		{
			con = DBManager.getConnection();
			pstmt = con.prepareStatement(sql);
			
			pstmt.setString(1, m.getPassword());
			pstmt.setString(2, m.getNick());
			pstmt.setString(3, m.getPicture());
			pstmt.setString(4, m.getEmail());
			
			int result = pstmt.executeUpdate();
			if(result == 0)
			{
				throw new MemberUpdateException();
			}
		}
		catch(SQLException | NamingException e)
		{
			e.printStackTrace();
			throw new MemberUpdateException();
		}
		finally
		{
			DBManager.close(pstmt, con);
		}
	}
	
	public MemberVO find(String email, String password) throws MemberException
	{
		String sql = "SELECT * FROM members WHERE email = ? AND pass = PASSWORD(?)";
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		MemberVO m = new MemberVO();
		
		try
		{
			con = DBManager.getConnection();
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, email);
			pstmt.setString(2, password);
			rs = pstmt.executeQuery();
			
			if(rs.next())
			{
				m.setEmail(rs.getString("email"));
				m.setPassword(rs.getString("pass"));
				m.setNick(rs.getString("nick"));
				m.setRegdate(rs.getString("regdate"));
				m.setRemoveAt(rs.getString("remove_at"));
				m.setPicture(rs.getString("picture"));
			}
			else
			{
				throw new LoginFailedException();
			}
		}
		catch(NamingException e)
		{
			e.printStackTrace();
			throw new LoginFailedException();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
			throw new LoginFailedException();
		}
		finally
		{
			DBManager.close(rs, pstmt, con);
		}
		return m;
	}
	
	public void insert(MemberVO m) throws MemberException
	{
		String sql = "INSERT INTO members VALUES(?, PASSWORD(?), ?, ?, default, ?)";
		Connection con = null;
		PreparedStatement pstmt = null;
		
		try
		{
			con = DBManager.getConnection();
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, m.getEmail());
			pstmt.setString(2, m.getPassword());
			pstmt.setString(3, m.getNick());
			pstmt.setString(4, m.getRegdate());
			pstmt.setString(5, m.getPicture());
			
			int result = pstmt.executeUpdate();
			
			if(result == 0)
			{
				throw new MemberInsertException();
			}
		}
		catch(NamingException e)
		{
			e.printStackTrace();
			throw new MemberInsertException();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
			throw new MemberInsertException();
		}
		finally
		{
			DBManager.close(pstmt, con);
		}
	}
}
