<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<c:if test='${empty loginUserInfo}'>
	<c:redirect url="../index.jsp"/>
</c:if>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>회원정보 변경</title>
<script src="../scripts/jquery-3.5.0.min.js"></script>
<script src="../scripts/public.js"></script>
<script src="../scripts/update.js"></script>
</head>
<body>
<form id="updateForm" method="post" 
		action="updateProc.jsp" enctype="multipart/form-data"> <!--없으면 String 타입으로 보낸다-->
<ul>
	<li>메일주소</li>
	<li><input type="text" name="email" id="email" size="30" value="${loginUserInfo.email}" onFocus="this.blur()"></li>
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
	<li><input type="text" name="nick" id="nick" size="15" value="${loginUserInfo.nick}"></li>
</ul>
<ul>
	<li>사진변경</li>
	<li>
		<ul>
			<li>
				<label for="change">변경함</label>
				<input type="radio" name="change" id="change" value="true">
			</li>
			<li>
				<label for="unchange">변경하지않음</label>
				<input type="radio" name="change" id="unchange" value="false" checked>
			</li>
		</ul>
	</li>
</ul>
<ul id="pictureField" style="display:none">
	<li>사진</li>
	<li><input type="file" name="picture"></li>
</ul>
<ul>
	<li><button type="button" id="btnRegister">변경하기</button></li>
</ul>
</form>

</body>
</html>