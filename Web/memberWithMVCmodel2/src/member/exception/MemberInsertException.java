package member.exception;

public class MemberInsertException extends MemberException
{
	private static final long serialVersionUID = 1L;
	public static final int ERRNO = 1;
	public static final String MESSAGE = "회원가입에 실패하였습니다.";
	
	public MemberInsertException()
	{
		super(ERRNO, MESSAGE);
	}
	
	@Override
	public void doException()
	{
		
	}
}