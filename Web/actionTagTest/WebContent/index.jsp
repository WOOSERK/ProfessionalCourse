<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.Date"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<fmt:setLocale value="ko_kr"></fmt:setLocale>
	<fmt:formatDate value="<%=new java.util.Date()%>" type="both"/>
	<fmt:formatNumber value="1000000" type="currency"/>
<fmt:setLocale value="ja_jp"></fmt:setLocale>
	<fmt:formatDate value="<%=new java.util.Date()%>"  type="both"/>
	<fmt:formatNumber value="1000000" type="currency"/>


</body>
</html>