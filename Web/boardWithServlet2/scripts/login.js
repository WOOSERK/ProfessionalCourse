$(document).ready(function()
{
	$('button').click(function()
	{
		if($('#email').val().trim() == '')
		{
			alert('메일 주소 확인해라^^');
			$('#email').val('').focus();
			return;
		}
		
		if($('#pass').val().trim() == '')
		{
			alert('비밀번호 확인해라^^');
			$('#pass').val('').focus();
			return;
		}
		
		$.ajax(
		{
			url: 'login',
			type: 'post',
			data:
			{
				email: $('#email').val(),
				pass: $('#pass').val()
			},
			success: function(data)
			{
				let d = eval('('+data+')');
				alert(d.message);
				
				if(d.errno == 0)
				{
					location.href = 'boardWrite.html';
				}
			}
		});
	});
});