<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<form action="registerProc.jsp" method="post" enctype="multipart/form-data">
	<input type="hidden" name="type" value="insert">
	<table style="margin: 0 auto">
		<tr>
			<th style="width: 100px">메일주소</th>
			<td style="width: 400px"><input type="text" name="email"></td>
		</tr>
		<tr>
			<th>제목</th>
			<td><input type="text" name="title"></td>
		</tr>
		<tr>
			<th>내용</th>
			<td><textarea name="content" rows="15" cols="50"></textarea></td>
		</tr>
		<tr>
			<th>파일첨부</th>
			<td><input type="file" name="attached"></td>
		</tr>
	</table>
	
	<div style="text-align: center">
		<button type="submit">전송하기</button>
	</div>
</form>
</body>
</html>