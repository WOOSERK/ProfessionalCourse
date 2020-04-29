package member.exception;

public class MemberDeleteException extends MemberException
{
	private static final long serialVersionUID = 1L;
	public static final int ERRNO = 4;
	public static final String MESSAGE = "회원탈퇴에 실패하였습니다.";
	
	public MemberDeleteException()
	{
		super(ERRNO, MESSAGE);
	}
	
	public void doException()
	{
	}
}
