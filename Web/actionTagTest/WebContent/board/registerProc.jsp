<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="kr.co.wooserk.vo.BoardVO"%>
<%@ page import="kr.co.wooserk.dao.BoardDAO"%>
<%@ page import="com.oreilly.servlet.MultipartRequest"%>
<%@ page import="com.oreilly.servlet.multipart.DefaultFileRenamePolicy"%>
<%@ page import="java.util.Calendar"%>
<%@ page import="java.text.SimpleDateFormat"%>

<jsp:useBean class="kr.co.wooserk.vo.BoardVO" id="board" scope="page"/>
<%
	MultipartRequest multi = new MultipartRequest(
								request,
								"C:/JSPWorkspace/ActionTagProject/WebContent/downloads",
								10 * 1024 * 1024,
								"utf-8",
								new DefaultFileRenamePolicy());
	board.setEmail(multi.getParameter("email"));
	board.setTitle(multi.getParameter("title"));
	board.setContent(multi.getParameter("content"));
	SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
	Calendar cal = Calendar.getInstance();
	board.setRegdate(sdf.format(cal.getTime()));
	board.setAttached(multi.getFilesystemName("attached"));
	
	BoardDAO dao = new BoardDAO();
	boolean result = dao.insert(board);
%>
<jsp:setProperty name="board" property="*"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

<%
	if(result)
	{
		out.println("<div>게시물 등록에 성공하였습니다.</div>");
		out.println("<div>");
		out.println("[<a href='list.jsp'>목록보기</a>]");
		out.println("</div>");
	}
	else
	{
		out.println("<div>게시물 등록에 실패하였습니다.</div>");
	}
%>

</body>
</html>