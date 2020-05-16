String.prototype.isEmpty=function(){
	return(this.trim()=='');
}

$.fn.isEmpty=function(){
	return($(this).val().trim()=='');
}

$.refresh=function(){
	$.ajax({
		url:'/board',
		type: 'get',
		success: function(data){
			$('.boardList').empty();
			let ul =$('<ul/>');
			$('<li/>',{text:'제목'}).appendTo(ul);
			$('<li/>',{text:'작성자'}).appendTo(ul);
			$('<li/>',{text:'비밀번호'}).appendTo(ul);
			$('<li/>',{text:'내용'}).appendTo(ul);
			
			$(data).each(function(index,item){
				$('<li/>',{text:item.b_title}).appendTo(ul);
				$('<li/>',{text:item.b_writer}).appendTo(ul);
				$('<li/>',{text:item.b_password}).appendTo(ul);
				$('<li/>',{text:item.b_contents}).appendTo(ul);
				ul.appendTo($('.boardList'));
			});
		}
	});
}


$(document).ready(function(){
	
	 var socket=io('http://192.168.30.19:8080');
	 socket.on('refresh', function(data){
		 $.refresh();
	 });
	 
	 $.refresh();
	 
	 $('#btnRegister').click(function(){
		 if($('#b_title').isEmpty()){
			alert('*알람: 제목을 입력하세요');
			$('#b_title').val('').focus();
			return;
		 }
		 
		 if($('#b_writer').isEmpty()){
				alert('*알람: 작성자를 입력하세요');
				$('#b_writer').val('').focus();
				return;
			 }
		 
		 if($('#b_password').isEmpty()){
				alert('*알람: 게시글의 비밀번호를 입력하세요');
				$('#b_password').val('').focus();
				return;
			 }
		 
		 if($('#b_contents').isEmpty()){
				alert('*알람: 내용을 입력하세요');
				$('#b_contents').val('').focus();
				return;
			 }
		 
		 
		 $.ajax({
			 url: '/board',
			 type: 'post',
			 data: {
				 b_title: $('#b_title').val(),
				 b_wirter: $('#b_writer').val(),
				 b_password: $('#b_password').val(),
				 b_contents: $('#b_contents').val()
			 },
			 success: function(data){
				 switch(data.errno){
				 case 0:
					alert(data.message);
					break;
				case 1:
					alert(data.message);
					$('#b_title').val('').focus();
					break;
				case 2:
					alert(data.message);
					$('#b_writer').val('').focus();
					break;
				case 3:
					alert(data.message);
					$('#b_password').val('').focus();
					break;
				case 4:
					alert(data.message);
					$('#b_contents').val('').focus();
					break;
				default:
					alert(data.message);
					break;
			 }
				
			 }
			
		 });
	 })
});
		