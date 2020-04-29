package member.exception;

public class MemberUpdateException extends MemberException
{
	private static final long serialVersionUID = 1L;
	public static final int ERRNO = 3;
	public static final String MESSAGE = "회원정보 변경에 실패하였습니다.";
	
	public MemberUpdateException()
	{
		super(ERRNO, MESSAGE);
	}
	
	public void doException()
	{
	
	}
}
