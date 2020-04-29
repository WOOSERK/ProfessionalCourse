<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>회원가입</title>
<script src="../scripts/jquery-3.5.0.min.js"></script>
<script src="../scripts/public.js"></script>
<script src="../scripts/register.js"></script>
</head>
<body>
<form id="regForm" method="post" 
		action="registerProc.jsp" enctype="multipart/form-data"> <!--없으면 String 타입으로 보낸다-->
<ul>
	<li>메일주소</li>
	<li><input type="text" name="email" id="email" size="30"></li>
</ul>
<ul>
	<li>비밀번호</li>
	<li><input type="password" name="password" id="password" size="20"></li>
</ul>
<ul>
	<li>비밀번호확인</li>
	<li><input type="password" name="password2" id="password2" size="20"></li>
</ul>
<ul>
	<li>별명</li>
	<li><input type="text" name="nick" id="nick" size="15"></li>
</ul>
<ul>
	<li>사진</li>
	<li><input type="file" name="picture"></li>
</ul>
<ul>
	<li><button type="button" id="btnRegister">등록하기</button></li>
</ul>
</form>
</body>
</html>