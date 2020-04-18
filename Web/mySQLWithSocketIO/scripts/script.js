String.prototype.isEmpty = function()
{
	return (this.trim() == '');
};

$.fn.isEmpty = function()
{
	return ($(this).val().trim() == '');
};

$.fn.equals = function(obj)
{
	return ($(this).val() == obj.val());
}

$.refresh = function()
{
	$.ajax(
	{
		url : '/members',
		type : 'get',
		success : function(data)
		{
			data.forEach(function(item, index)
			{
			var ul = $('<ul>').appendTo('.memberList');
			ul.append($('<li>').text(item.email));
			ul.append($('<li>').text(item.nick));
			ul.append($('<li>').text(item.regDate));
			ul.append($('<li>').text((item.removeAt==null) ? '가입중' : item.removeAt));
			});
		}
	})
}


$(document).ready(function()
{
	var socket = io('http://192.168.30.19:8080');
	socket.on('refresh', function()
	{
		$.refresh();
	});
	
	$.refresh();
	
	$('#btnRegister').click(function()
	{
		if ($('#email').val().isEmpty())
		{
			alert('메일주소 입력하셈');
			$('#email').val('').focus(); // 모듈화 가능
			return;
		}
		
		if($('#nick').isEmpty())
		{
			alert('별명 입력하셈');
			return;
		}
		
		if($('#password').isEmpty())
		{
			alert('비밀번호 입력하셈');
			return;
		}
		
		if($('#password2').equals($('#password')))
		{
			alert('비밀번호와 비밀번호 확인이 일치하지 않음');
			$('#password2').val('').focus();
			return;
		}
		
		$.ajax(
		{ 
			url : '/members',
			type: 'post',
			data: 
			{
				email: $('#email').val(),
				nick: $('#nick').val(),
				password: $('#password').val()
			},
			success: function(data)
			{
				switch(data.errno)
				{
				case 0:
					alert(data.message);
					break;
				case 1:
					alert(data.message);
					$('#email').val('').focus();
					break;
				case 2:
					alert(data.message);
					$('#nick').val('').focus();
					break;
				case 3:
					alert(data.message);
					$('#password2').val('');
					$('#password').val('').focus();
					break;
				default:
					alert(data.message);
					break;
				}
			}
		});
	});
	

});