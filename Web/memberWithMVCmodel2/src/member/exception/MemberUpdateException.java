package member.exception;

public class MemberUpdateException extends MemberException
{
	private static final long serialVersionUID = 1L;
	public static final int ERRNO = 3;
	public static final String MESSAGE = "ȸ������ ���濡 �����Ͽ����ϴ�.";
	
	public MemberUpdateException()
	{
		super(ERRNO, MESSAGE);
	}
	
	public void doException()
	{
	
	}
}
