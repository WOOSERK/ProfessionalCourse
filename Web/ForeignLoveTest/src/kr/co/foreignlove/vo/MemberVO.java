package kr.co.foreignlove.vo;

public class MemberVO
{
	private String id;
	private String pass;
	
	public MemberVO() {}
	
	public MemberVO(String id, String pass)
	{
		this.id = id;
		this.pass = pass;
	}
	
	public String getId()
	{
		return id;
	}
	
	public String getPass()
	{
		return pass;
	}
	
	public void setId(String id)
	{
		this.id = id;
	}
	
	public void setPass(String pass)
	{
		this.pass = pass;
	}
}
