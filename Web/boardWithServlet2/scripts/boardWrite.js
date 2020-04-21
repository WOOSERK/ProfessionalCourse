$(document).ready(function()
{
	$('button').click(function()
	{
		if($('#title').val().trim() == '')
		{
			alert('제목이 비었슴다.');
			$('#title').val('').focus();
			return;
		}
		if($('#content').val().trim() == '')
		{
			alert('내용이 비었슴다.');
			$('#content').val('').focus();
			return;
		}
		
		$.ajax(
		{
			url: 'boardWrite',
			method: 'post',
			data: 
			{
				title: $('#title').val(),
				content: $('#content').val(),
			}
		}).done(function(data)
		{
			var obj = eval('('+data+')');
			alert(obj.message);
			if(obj.errno == 9)
			{
				location.href = 'login.html';
			}
		});
	});
});