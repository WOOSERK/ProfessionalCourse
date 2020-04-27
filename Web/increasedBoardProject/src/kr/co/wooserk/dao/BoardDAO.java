package kr.co.wooserk.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import javax.naming.NamingException;

import kr.co.wooserk.controller.DBManager;
import kr.co.wooserk.vo.BoardVO;
import kr.co.wooserk.service.BoardService;

public class BoardDAO
{
	public BoardDAO() {}
	
	public int getTotalRecord(String condition, String word)
	{
		StringBuffer sb = new StringBuffer("SELECT COUNT(*) FROM boards ");
		
		switch(condition)
		{
		case BoardService.CONDITION_TITLE:
			sb.append("WHERE title LIKE '%" + word + "%' ");
			break;
		case BoardService.CONDITION_CONTENT:
			sb.append("WHERE content LIKE '%" + word + "%' ");
			break;
		default:
			sb.append(" WHERE title LIKE '%" + word + "%' ");
			sb.append("OR content LIKE '%" + word + "%' ");
			sb.append("");
		}
		
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		int rowCount = 0;
		
		try
		{
			con = DBManager.getConnection();
			stmt = con.createStatement();
			rs = stmt.executeQuery(sb.toString());
			if(rs.next())
			{
				rowCount = rs.getInt(1);
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			DBManager.close(rs, stmt, con);
		}
		
		return rowCount;
	}
	
	public ArrayList<BoardVO> getList(int page, int pageSize, String condition, String word)
	{
		StringBuffer sb = new StringBuffer();
		sb.append("SELECT * FROM boards ");
		switch(condition)
		{
		case BoardService.CONDITION_TITLE:
			sb.append(" WHERE title LIKE '%" + word + "%' ");
			break;
		case BoardService.CONDITION_CONTENT:
			sb.append(" WHERE content LIKE '%" + word + "%' ");
			break;
		default:
			sb.append(" WHERE title LIKE '%" + word + "%' ");
			sb.append("OR content LIKE '%" + word + "%' ");
			break;
		}
		
		int startPos = (page - 1) * pageSize;
		sb.append("ORDER BY id DESC ");
		sb.append("LIMIT " + startPos + ", " + pageSize);
		
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<BoardVO> list = new ArrayList<>();
		
		try
		{
			con = DBManager.getConnection();
			stmt = con.createStatement();
			rs = stmt.executeQuery(sb.toString());
			
			while(rs.next())
			{
				BoardVO board = new BoardVO();
				board.setId(rs.getInt("id"));
				board.setEmail(rs.getString("email"));
				board.setTitle(rs.getString("title"));
				board.setContent(rs.getString("content"));
				board.setRegdate(rs.getString("regdate"));
				board.setCnt(rs.getInt("cnt"));
				board.setAttached(rs.getString("attached"));
				
				list.add(board);
			}
		}
		catch(Exception e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			DBManager.close(rs, stmt, con);
		}
		
		return list;
	}
	
	public BoardVO getBoard(int id)
	{
		String sql = "SELECT * FROM boards WHERE id = " + id;
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		BoardVO board = null;
		
		try
		{
			con = DBManager.getConnection();
			stmt = con.createStatement();
			rs = stmt.executeQuery(sql);
			
			if(rs.next())
			{
				board = new BoardVO();
				board.setId(rs.getInt("id"));
				board.setEmail(rs.getString("email"));
				board.setTitle(rs.getString("title"));
				board.setContent(rs.getString("content"));
				board.setRegdate(rs.getString("regdate"));
				board.setCnt(rs.getInt("cnt"));
				board.setAttached(rs.getString("attached"));
			}
		}
		catch(Exception e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			DBManager.close(rs, stmt, con);;
		}
		
		return board;
	}
	
	public boolean update(BoardVO board)
	{
		String sql = "UPDATE boards SET title = ?, content = ?, attached = ? WHERE id = ?";
		Connection con = null;
		PreparedStatement pstmt = null;
		boolean result = false;
		
		try
		{
			con = DBManager.getConnection();
			pstmt = con.prepareStatement(sql);
			
			pstmt.setString(1, board.getTitle());
			pstmt.setString(2, board.getContent());
			pstmt.setString(3, board.getAttached());
			pstmt.setInt(4, board.getId());
			
			result = (pstmt.executeUpdate() > 0);
		}
		catch(Exception e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			DBManager.close(pstmt, con);
		}
		
		return result;
	}
	
	public boolean delete(int id)
	{
		String sql = "DELETE FROM boards WHERE id = " + id;
		Connection con = null;
		Statement stmt = null;
		boolean result = false;
		
		try
		{
			con = DBManager.getConnection();
			stmt = con.createStatement();
			result = (stmt.executeUpdate(sql) > 0);
		}
		catch(Exception e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			DBManager.close(stmt, con);
		}
		
		return result;
	}
	
	private int getLastInsertId(Connection con) throws SQLException
	{
		String sql = "SELECT LAST_INSERT_ID()";
		Statement stmt = null;
		ResultSet rs = null;
		int id = 0;
		
		stmt = con.createStatement();
		rs = stmt.executeQuery(sql);
		if(rs.next())
		{
			id = rs.getInt(1);
		}
		DBManager.close(rs, stmt);
		return id;
	}
	
	public boolean insert(BoardVO board)
	{
		String sql = "INSERT INTO boards VALUES(default, ?, ?, ?, default, default, ?)";
		
		Connection con = null;
		PreparedStatement pstmt = null;
		boolean result = false;
		
		try
		{
			con = DBManager.getConnection();
			pstmt = con.prepareStatement(sql);
	
			pstmt.setString(1, board.getEmail());
			pstmt.setString(2, board.getTitle());
			pstmt.setString(3, board.getContent());
			pstmt.setString(4, board.getAttached());
			result = (pstmt.executeUpdate() > 0);
			int id = getLastInsertId(con);
			board.setId(id);
		}
		catch(NamingException e)
		{
			System.err.println(e.getMessage());
		}
		catch(SQLException e)
		{
			System.err.println(e.getMessage());
		}
		catch(Exception e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			DBManager.close(pstmt, con);
		}
		
		return result;
	}
}
