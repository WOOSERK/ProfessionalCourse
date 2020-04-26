package kr.co.wooserk.controller;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;

public class DBManager
{
	public Connection getConnection() throws NamingException, SQLException
	{
		InitialContext ic = new InitialContext();
		DataSource ds = (DataSource)ic.lookup("java:comp/env/jdbc/servlet");
		
		return ds.getConnection();
	}
	
	public void close(ResultSet rs)
	{
		try {rs.close();}catch(Exception e) {}
	}
	
	public void close(Statement stmt)
	{
		try {stmt.close();}catch(Exception e) {}
	}
	
	public void close(Connection con)
	{
		try {con.close();}catch(Exception e) {}
	}
	
	public void close(ResultSet rs, Statement stmt)
	{
		close(rs);
		close(stmt);
	}
	
	public void close(Statement stmt, Connection con)
	{
		close(stmt);
		close(con);
	}
	
	public void close(ResultSet rs, Statement stmt, Connection con)
	{
		close(rs);
		close(stmt);
		close(con);
	}
}
