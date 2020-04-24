package kr.co.wooserk.vo;

public class Member 
{
	private String email;
	private String password;
	private String nick;
	private String regdate;
	private String removeAt;
	
	public Member() {}
	
	public Member(String email, String password, String nick, String regdate,
			String removeAt)
	{
		this.email = email;
		this.password = password;
		this.nick = nick;
		this.regdate = regdate;
		this.removeAt = removeAt;
	}
	
	public String getEmail()
	{
		return email;
	}
	
	public void setEmail(String email)
	{
		this.email = email;
	}
	
	public String getPassword()
	{
		return password;
	}
	
	public void setPassword(String password)
	{
		this.password = password;
	}
	
	public String getNick()
	{
		return nick;
	}
	
	public void setNick(String nick)
	{
		this.nick = nick;
	}
	
	public String getRegdate()
	{
		return regdate;
	}
	
	public void setRegdate(String regdate)
	{
		this.regdate = regdate;
	}
	
	public String getRemoveAt()
	{
		return removeAt;
	}
	
	public void setRemoveAt(String removeAt)
	{
		this.removeAt = removeAt;
	}
}
