package member.exception;

public class LoginFailedException extends MemberException
{
	private static final long serialVersionUID = 1L;
	public static final int ERRNO = 2;
	public static final String MESSAGE = "�α��ο� �����Ͽ����ϴ�.";
	
	public LoginFailedException()
	{
		super(ERRNO, MESSAGE);
	}
	
	public void doException()
	{
	}
}
