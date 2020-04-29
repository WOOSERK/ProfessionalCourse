package member.exception;

public abstract class MemberException extends Exception
{
	private static final long serialVersionUID = 1L;
	protected int errno;
	
	public MemberException(String message)
	{
		super(message);
	}
	
	public MemberException(int errno, String message)
	{
		this(message);
		this.errno = errno;
	}
	
	public int getErrno()
	{
		return errno;
	}
	
	public abstract void doException();
}