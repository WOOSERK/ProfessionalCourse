package member.exception;

public class MemberDeleteException extends MemberException
{
	private static final long serialVersionUID = 1L;
	public static final int ERRNO = 4;
	public static final String MESSAGE = "ȸ��Ż�� �����Ͽ����ϴ�.";
	
	public MemberDeleteException()
	{
		super(ERRNO, MESSAGE);
	}
	
	public void doException()
	{
	}
}
