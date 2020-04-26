package kr.co.wooserk.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import javax.naming.NamingException;

import kr.co.wooserk.controller.DBManager;
import kr.co.wooserk.vo.BoardVO;

public class BoardDAO
{
	public boolean insert(BoardVO board)
	{
		boolean result = false;
		
		Connection con = null;
		PreparedStatement pstmt = null;
		DBManager dbManager = new DBManager();
		
		try
		{
			con = dbManager.getConnection();
			pstmt = con.prepareStatement("INSERT INTO boards(email, title, content) VALUES(?, ?, ?)");
			pstmt.setString(1, board.getEmail());
			pstmt.setString(2, board.getTitle());
			pstmt.setString(3, board.getContent());
			
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
			dbManager.close(pstmt, con);
		}
		
		return result;
	}
	
	public boolean delete(BoardVO board)
	{
		boolean result = false;
		Connection con = null;
		PreparedStatement pstmt = null;
		DBManager dbManager = new DBManager();
		
		try
		{
			con = dbManager.getConnection();
			pstmt = con.prepareStatement("DELETE FROM boards WHERE id = ?");
			
			pstmt.setInt(1, board.getId());
			if(pstmt.executeUpdate() > 0)
			{
				result = true;
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
			dbManager.close(pstmt, con);
		}
		
		return result;
	}
	
	public boolean delete(int id)
	{
		BoardVO board = new BoardVO();
		board.setId(id);
		
		return delete(board);
	}
	
	public boolean update(BoardVO board)
	{
		boolean result = false;
		Connection con = null;
		PreparedStatement pstmt = null;
		DBManager dbManager = new DBManager();
		
		try
		{
			con = dbManager.getConnection();
			pstmt = con.prepareStatement("UPDATE boards SET title = ? AND content = ? WHERE id = ?");
			pstmt.setString(1, board.getTitle());
			pstmt.setString(2, board.getContent());
			pstmt.setInt(3, board.getId());
			
			if(pstmt.executeUpdate() > 0)
			{
				result = true;
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
			dbManager.close(pstmt, con);
		}
		
		return result;
	}
	
	public BoardVO find(int id)
	{
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		DBManager dbManager = new DBManager();
		BoardVO board = null;
		
		try
		{
			con = dbManager.getConnection();
			pstmt = con.prepareStatement("SELECT * FROM boards WHERE id = ?");
			pstmt.setInt(1, id);
			rs = pstmt.executeQuery();
			
			if(rs.next())
			{
				board = new BoardVO();
				board.setId(rs.getInt("id"));
				board.setEmail(rs.getString("email"));
				board.setTitle(rs.getString("title"));
				board.setContent(rs.getString("content"));
				board.setWdate(rs.getString("regdate"));
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
		
		return board;
	}
	
	public ArrayList<BoardVO> getList(int page, int pageSize, String cond, String word)
	{
		ArrayList<BoardVO> list = new ArrayList<>();
		
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		DBManager dbManager = new DBManager();
		
		try
		{
			con = dbManager.getConnection();
			pstmt = con.prepareStatement("SELECT * FROM boards"); // WHERE ? LIKE '%?%' LIMIT ?, ?
			
			/*
			 * pstmt.setString(1, cond); pstmt.setString(2, word); pstmt.setInt(3,
			 * (page-1)*pageSize); pstmt.setInt(4, pageSize);
			 */
			rs = pstmt.executeQuery();
			
			while(rs.next())
			{
				list.add(new BoardVO(rs.getInt("id"),
						rs.getString("email"),
						rs.getString("title"),
						rs.getString("content"),
						rs.getString("regdate"),
						null));
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
		
		return list;
	}
	
	public int getPageCount(int pageSize)
	{
		int result = 0;
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		DBManager dbManager = new DBManager();
		
		try
		{
			con = dbManager.getConnection();
			pstmt = con.prepareStatement("SELECT CEIL(COUNT(*)/?) FROM boards");
			pstmt.setInt(1, pageSize);
			rs = pstmt.executeQuery();
			
			if(rs.next())
			{
				result = rs.getInt(1);
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
		
		return result;
	}
}
